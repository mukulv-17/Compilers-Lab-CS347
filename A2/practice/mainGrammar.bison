statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

compound_statement
	: LCB RCB
	| LCB block_item_list RCB
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
: SEMICOLON
| expression SEMICOLON
;

selection_statement
	: IF LP expression RP statement
	| IF LP expression RP statement ELSE statement


iteration_statement
	: WHILE LP expression RP statement
	| FOR LP expression_statement expression_statement RP statement
	| FOR LP expression_statement expression_statement expression RP statement
	| FOR LP declaration expression_statement RP statement
	| FOR LP declaration expression_statement expression RP statement

jump_statement
	: CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

expression
	: assignment_expression
	| expression COMMA assignment_expression
	| PROCESSOR 
	| CLUSTER 
	| LINK  
	| MEMORY 
	| JOB 
	| IS_RUNNING 
	| SUBMIT_JOBS 
	| GCS 
	| GAV 
	| RUN 
	| DJ 
	| GM 
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

conditional_expression
	: logical_or_expression	;


declaration
	: type_specifier SEMICOLON
	| type_specifier init_declarator_list SEMICOLON
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	;
init_declarator_list
	: init_declarator
	| init_declarator_list COMMA init_declarator
	;

init_declarator
	: declarator
	| declarator ASSIGN initializer
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
	;
	
primary_expression
	: ID
	| CONSTANT
	| STRING_LITERAL
	| LP expression RP
	;


postfix_expression
	: primary_expression
	| postfix_expression LSB expression RSB
	| postfix_expression LP RP
	| postfix_expression LP argument_expression_list RP
	| postfix_expression '.' ID 
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

multiplicative_expression
	: postfix_expression
	| multiplicative_expression TIMES postfix_expression
	| multiplicative_expression DIV postfix_expression
	| multiplicative_expression PERCENT postfix_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression PLUS multiplicative_expression
	| additive_expression MINUS multiplicative_expression
	;

relational_expression
	: additive_expression
	| relational_expression LT additive_expression
	| relational_expression GT additive_expression
	| relational_expression LE_OP additive_expression
	| relational_expression GE_OP additive_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression BIT_AND equality_expression
	; 

inclusive_or_expression
	: and_expression
	| inclusive_or_expression BIT_OR exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;