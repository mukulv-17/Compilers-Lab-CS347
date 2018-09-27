%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char* s);
extern int yylex();
extern int yyparse();

#define YYDEBUG_VAL 1

%}
	//^equivalent to --debug option
%define parse.error verbose
	//^ prints a verbose error, but may be incorrect
	// %define api.pure full
%token TYPE_NAME VOID CONSTANT
%token LEFT_OP RIGHT_OP 
%token IDENTIFIER FLOAT_CONST BOOL
%token STRING_LITERAL CONST CHAR INT LONG RETURN SHORT SIGNED UNSIGNED INTEGER FLOAT DOUBLE
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN 
%token INC_OP DEC_OP PTR_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP  
%token DO WHILE ELSE FOR IF BREAK CONTINUE
%token MF_GET_MEMORY MF_IS_RUNNING MF_SUBMIT_JOBS MF_GET_CS MF_RUN MF_DISCARD_JOB MF_GAV
%token P_NAME P_ISA P_CLOCK_SPEED P_MEM_OBJ_1 P_MEM_OBJ_2 P_START_POINT P_END_POINT P_BANDWIDTH P_CHANNEL_CAP P_MEM_TYPE P_MEM_SIZE P_JOB_ID P_FLOPS_REQ P_DEADLINE P_MEM_REQ P_AFFINITY P_PROCESSORS P_LINK_BANDW P_LINK_CAP P_TOPOLOGY
%token C_PROC C_CLUSTER C_LINK C_MEMORY C_JOB

%start translation_unit

%%

translation_unit 
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;


primary_expression //PRI
	: id_or_float
	| STRING_LITERAL
	| '(' expression ')'
	| special_expression
	;

id_or_float
	: FLOAT_CONST
	| id_or_int

id_or_int
	: INTEGER
	| IDENTIFIER

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' special_function
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;
		//| postfix_expression '.' IDENTIFIER

special_function
	:is_running 
	|submit_jobs 
	|get_clock_speed  
	|discard_job
	|get_available_memory
	|get_memory 
	;

	//postfix_expression -> PRI ('['expression']' |'('')'|'('argument_expression_list')'|.id )*
	//argument_expression_list -> (unary_expression = unary_expression =...=conditional_expression',') * 


unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	;

	//unary_expression ->  ((&|*|+|-|!) '('type_name')'+)* postfix_expression 
	//postfix_expression -> PRI ('['expression']' |'('')'|'('argument_expression_list')'|.id )*
	//argument_expression_list -> (unary_expression = unary_expression =...=conditional_expression',') * 

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_specifier ')' unary_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;
	//logical_or_expression ->(((((((((( '('type_name')'* unary_expression '*|/|%')* '+|-')*'<<|>>')*'<|>|<=|>=')*'==|!=')*'&')*'^')*'|')* '&&')* '||')*
	//unary_expression ->  ((&|*|+|-|!) '('type_name')'+)* PRI ('['expression']' |'('')'|'('(unary_expression=)*conditional_expression')'|.id )*


conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

	// a ? b,e:c  evaluates to a ? e : c
	// a ? b :c ,e evaluates to e	

special_expression
	:processor
	|run
	|link
	|memory
	|job
	|cluster
	;


assignment_expression
	: conditional_expression
	| unary_expression '=' assignment_expression
	;


expression
	: assignment_expression
	| expression ',' assignment_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator '=' assignment_expression
	| declarator
	;

declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
	;


type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| BOOL
	;


declarator
	: IDENTIFIER
	| '(' declarator ')'
	| declarator '[' assignment_expression ']'
	| declarator '[' '*' ']'
	| declarator '[' ']'
	| declarator '(' parameter_list ')'
	| declarator '(' identifier_list ')'
	| declarator '(' ')'
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers
	;
	// declaration_specifiers -> type_specifier+
identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;


	//type_name -> type_specifier* [direct_abstract_declarator];

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

compound_statement
	: '{' '}'
	| '{' block_item_list '}'
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	| FOR '(' declaration expression_statement ')' statement
	| FOR '(' declaration expression_statement expression ')' statement
	;

jump_statement
	: IDENTIFIER ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

	//cidentifers → ID,cidentifers | ID
cidentifers
	:IDENTIFIER
	|IDENTIFIER ','cidentifers
	;



	//Comma Separated String Arguments-
cstrings
	: STRING_LITERAL 
	| ',' P_NAME'='STRING_LITERAL 
	| ',' P_NAME '=' "None"
	| %empty //the epsilon
	;


	//----------------------------------------------------------Processor Class------------------------------------------------------------------------------------------
processor 
	: C_PROC'('processor_isa ',' processor_clock_speed ',' processor_l1 processor_optional')'
	;
	
	//PI → isa=STRING_LITERAL
processor_isa
	: P_ISA '=' STRING_LITERAL
	| STRING_LITERAL
	;
	

	//PCS → clock_speed : FLOAT
processor_clock_speed
	: P_CLOCK_SPEED ':' assignment_expression
	| assignment_expression
	;
	
	//PL1 → l1_memory=L1
processor_l1
	: P_MEM_OBJ_1 '=' l1
	| l1
	;

l1 
	: IDENTIFIER 
	| memory
	;

processor_optional 
	:  ',' P_MEM_OBJ_2_EQ l1 cstrings 
	|  ',' P_MEM_OBJ_2_EQ "None" cstrings 
	| cstrings
	;

P_MEM_OBJ_2_EQ	
	: P_MEM_OBJ_2 '='
	| %empty
	;

is_running 
	: IDENTIFIER '.' MF_IS_RUNNING '('  ')'  
	;
submit_jobs 
	: MF_SUBMIT_JOBS '(' cluster_array ')'  
	;
get_clock_speed 
	: IDENTIFIER '.' MF_GET_CS '('  ')'   
	;
run 
	: MF_RUN '(' cluster_array ')'  
	;
discard_job 
	: IDENTIFIER '.' MF_DISCARD_JOB '(' IDENTIFIER ')'  
	;

	//---------------------------------------------------Link Class--------------------------------------------------------------------------------------
link 
	: C_LINK '(' link_start_point ',' link_end_point ',' link_bandwidth ','  assignment_expression cstrings ')'  
	;
link_start_point 
	: P_START_POINT '=' STRING_LITERAL
	| STRING_LITERAL
	;
link_end_point 
	: P_END_POINT '=' STRING_LITERAL
	| STRING_LITERAL
	;
link_bandwidth 
	: P_BANDWIDTH '=' assignment_expression
	| assignment_expression
	;
	
	//---------------------------------------------------Memory Class-------------------------------------------------------------------------------------
memory 
	: C_MEMORY'('P_MEM_TYPE_EQ STRING_LITERAL ','  P_MEM_SIZE_EQ assignment_expression cstrings ')'  
	;

P_MEM_TYPE_EQ
	:P_MEM_TYPE '=' 
	| %empty
	;
P_MEM_SIZE_EQ
	:P_MEM_SIZE '=' 
	| %empty
	;
	//Member Functions
get_available_memory 
	: IDENTIFIER '.' MF_GAV '('  ')'  
	;

	//-------------------------------------------------------Job Class-------------------------------------------------------------------------
job 
	: C_JOB '(' job_id ',' job_flops_required ',' job_deadline ',' job_memory_required ',' job_affinity')' 
	;

job_id 
	: P_JOB_ID '=' assignment_expression
	| assignment_expression
	;
job_flops_required 
	: P_FLOPS_REQ '=' assignment_expression
	| assignment_expression
	;
job_deadline 
	: P_DEADLINE '=' assignment_expression
	| assignment_expression
	;
job_memory_required 
	: P_MEM_REQ '=' assignment_expression
	| assignment_expression
	;
job_affinity 
	: P_AFFINITY '=' affinity
	| affinity
	;
	// array of floats can also be passed as a variable
affinity 
	: IDENTIFIER 
	|   '[' assignment_expression ','  assignment_expression ','  assignment_expression ','  assignment_expression ']' 
	;
	//Member Functions

get_memory 
	: IDENTIFIER '.' MF_GET_MEMORY '('  ')'   
	;
	
	//-------------------------------------------------------Cluster Class-----------------------------------------------------------------------
cluster 
	: C_CLUSTER '(' cluster_processors ',' cluster_topology ',' cluster_link_bandwidth ',' cluster_link_capacity cstrings ')'  
	;
cluster_processors 
	: P_PROCESSORS '=' cluster_array
	| cluster_array
	;
cluster_topology 
	: P_TOPOLOGY '=' STRING_LITERAL
	| STRING_LITERAL
	;
cluster_link_bandwidth 
	: P_LINK_BANDW '=' assignment_expression
	| assignment_expression
	;
cluster_link_capacity 
	: P_LINK_CAP '=' assignment_expression
	| assignment_expression
	;
cluster_array 
	: IDENTIFIER 
	|  '[' cidentifers ']' 
	;


%%
extern char* yytext;
extern int line_no;
extern int column;
char* input_filename="main.in";

void printLine(int line_no){
	int line = 1;
	char temp[500],nl;//line buffer
	FILE* yyerrFile = fopen(input_filename,"r");

	while(fgets(temp,sizeof temp, yyerrFile)!=NULL){
		if(line == line_no){
			if(temp[strlen(temp)-1]!='\n')
				nl='\n';
			printf("%s%c",temp,nl);
			break;
		}else{
			line++;
		}

	}
	fclose(yyerrFile);
}
void yyerror(const char* error_msg)
{
	//called by bison on syntax error
	fflush(stdout);
	printf("Error at line number: %d\n", line_no);
	printLine(line_no);
//	printf("%*s\n%*s\n", column, "^", column, error_msg);
	printf("%s\n",error_msg);
//	exit(1); // it exits by itself anyway
}

extern FILE* yyin;

int main(int argc, char* argv[]){
	if(argc>1)
		input_filename = argv[1];
	yyin = fopen(input_filename,"r");

	int err = 0;
	#if YYDEBUG
		yydebug=YYDEBUG_VAL;
	#endif
	do { 
		err = yyparse();
	} while(!feof(yyin));
	if(err==0)
		printf("File parsed successfully!\n");
	fclose(yyin);
	return 0;
}
