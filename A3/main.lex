%option noyywrap
    // %option yylineno
    //^ yylineno option makes it 'extern'able to bison, but the yylineno can sometimes be off by one
    
    //SelfNote for tokens: could've used [][=+*...]     return yytext[0]; and use the characters directly in grammar 

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.tab.h" // for YYTYPE, need to use -d option of bison to generate this.

void comment(void);
void count(void);
int line_no=1;// still used for clarity
%}


D                    [0-9]
L                    [a-zA-Z_]


%%
"/*"                    { comment(); }
" //".*$                    { /* eat single line comments */}


"break"                    {  count(); /*printf("%s \t<--BREAK\n",yytext);*/ return(BREAK); }
"char"                    {  count(); /*printf("%s \t<--CHAR\n",yytext);*/ return(CHAR); }
"const"                    {  count(); /*printf("%s \t<--CONST\n",yytext);*/ return(CONST); }
"continue"            {  count(); /*printf("%s \t<--CONTINUE\n",yytext);*/ return(CONTINUE); }
"do"                    {  count(); /*printf("%s \t<--DO\n",yytext);*/ return(DO); }
"double"            {  count(); /*printf("%s \t<--DOUBLE\n",yytext);*/ return(DOUBLE); }
"else"                    {  count(); /*printf("%s \t<--ELSE\n",yytext);*/ return(ELSE); }
"float"                    {  count(); /*printf("%s \t<--FLOAT\n",yytext);*/ return(FLOAT); }
"for"                    {  count(); /*printf("%s \t<--FOR\n",yytext);*/ return(FOR); }
"if"                    {  count(); /*printf("%s \t<--IF\n",yytext);*/ return(IF); }
"int"                    {  count(); /*printf("%s \t<--INT\n",yytext);*/ return(INT); }
"long"                    {  count(); /*printf("%s \t<--LONG\n",yytext);*/ return(LONG); }
"return"            {  count(); /*printf("%s \t<--RETURN\n",yytext);*/ return(RETURN); }
"short"                    {  count(); /*printf("%s \t<--SHORT\n",yytext);*/ return(SHORT); }
"signed"            {  count(); /*printf("%s \t<--SIGNED\n",yytext);*/ return(SIGNED); }
"unsigned"            {  count(); /*printf("%s \t<--UNSIGNED\n",yytext);*/ return(UNSIGNED); }
"while"                    {  count(); /*printf("%s \t<--WHILE\n",yytext);*/ return(WHILE); }
    
    /*------------------extended language keywords----------*/
name                            { count(); /*printf("%s \t<--P_NAME\n",yytext);*/ return(P_NAME);}


    /*--------------------------PROCESSOR CLASS----------------------------*/
Processor                    { count(); /*printf("%s \t<--C_PROC\n",yytext);*/ return(C_PROC);}
isa                                    { count(); /*printf("%s \t<--P_ISA\n",yytext);*/ return(P_ISA);}    
clock_speed                    { count(); /*printf("%s \t<--P_CLOCK_SPEED\n",yytext);*/ return(P_CLOCK_SPEED);}
l1_memory            { count(); /*printf("%s \t<--P_MEM_OBJ_1\n",yytext);*/ return(P_MEM_OBJ_1);}
l2_memory            { count(); /*printf("%s \t<--P_MEM_OBJ_2\n",yytext);*/ return(P_MEM_OBJ_2);}


is_running                    { count(); /*printf("%s \t<--MF_IS_RUNNING\n",yytext);*/ return(MF_IS_RUNNING);}
submit_jobs                    { count(); /*printf("%s \t<--MF_SUBMIT_JOBS\n",yytext);*/ return(MF_SUBMIT_JOBS);}
get_clock_speed            { count(); /*printf("%s \t<--MF_GET_CS\n",yytext);*/ return(MF_GET_CS);}
run                                  { count(); /*printf("%s \t<--MF_RUN\n",yytext);*/ return(MF_RUN);}
discard_job                    { count(); /*printf("%s \t<--MF_DISCARD_JOB\n",yytext);*/ return(MF_DISCARD_JOB);}


    /*---------------------LINK CLASS ------------------------*/
Link                            { count(); /*printf("%s \t<--C_LINK\n",yytext);*/ return(C_LINK);}
start_point             { count(); /*printf("%s \t<--P_START_POINT\n",yytext);*/ return(P_START_POINT);}
end_point                     { count(); /*printf("%s \t<--P_END_POINT\n",yytext);*/ return(P_END_POINT);}
bandwidth                     { count(); /*printf("%s \t<--P_BANDWIDTH\n",yytext);*/ return(P_BANDWIDTH);}
channel_capacity     { count(); /*printf("%s \t<--P_CHANNEL_CAP\n",yytext);*/ return(P_CHANNEL_CAP);}
    
    /*--------------------MEMORY CLASS-------------------*/
Memory                             { count(); /*printf("%s \t<--C_MEMORY\n",yytext);*/ return(C_MEMORY);}
memory_type                    { count(); /*printf("%s \t<--P_MEM_TYPE\n",yytext);*/ return(P_MEM_TYPE);}
mem_size                     { count(); /*printf("%s \t<--P_MEM_SIZE\n",yytext);*/ return(P_MEM_SIZE);}


    /*--------------------JOB CLASS---------------------*/
Job                             { count(); /*printf("%s \t<--C_JOB\n",yytext);*/ return(C_JOB);}
job_id                            { count(); /*printf("%s \t<--P_JOB_ID\n",yytext);*/ return(P_JOB_ID);}
flops_required            { count(); /*printf("%s \t<--P_FLOPS_REQ\n",yytext);*/ return(P_FLOPS_REQ);}
deadline                    { count(); /*printf("%s \t<--P_DEADLINE\n",yytext);*/ return(P_DEADLINE);}
mem_required            { count(); /*printf("%s \t<--P_MEM_REQ\n",yytext);*/ return(P_MEM_REQ);}
affinity                    { count(); /*printf("%s \t<--P_AFFINITY\n",yytext);*/ return(P_AFFINITY);}


get_memory                    { count(); /*printf("%s \t<--MF_GET_MEMORY\n",yytext);*/ return(MF_GET_MEMORY);}


    /*---------------CLUSTER CLASS----------------*/
Cluster                     { count(); /*printf("%s \t<--C_CLUSTER\n",yytext);*/ return(C_CLUSTER);}
processors                    { count(); /*printf("%s \t<--P_PROCESSORS\n",yytext);*/ return(P_PROCESSORS);}    
topology                    { count(); /*printf("%s \t<--P_TOPOLOGY\n",yytext);*/ return(P_TOPOLOGY);}
link_bandwidth            { count(); /*printf("%s \t<--P_LINK_BANDW\n",yytext);*/ return(P_LINK_BANDW);}
link_capacity            { count(); /*printf("%s \t<--P_LINK_CAP\n",yytext);*/ return(P_LINK_CAP);}


{L}({L}|{D})*            {  count(); /*printf("%s \t<--IDENTIFIER\n",yytext);*/ return(IDENTIFIER); }


{D}+            {  count(); /*printf("%s \t<--INTEGER\n",yytext);*/ return(INTEGER); }
({D}+"."{D}*)|({D}*"."{D}+)            {  count(); /*printf("%s \t<--FLOAT_CONST\n",yytext);*/ return(FLOAT_CONST); }


L?\"(\\.|[^\\"\n])*\"    {  count(); /*printf("%s \t<--STRING_LITERAL\n",yytext);*/ return(STRING_LITERAL); }
L?\'(\\.|[^\\"\n])*\'    {  count(); /*printf("%s \t<--STRING_LITERAL\n",yytext);*/ return(STRING_LITERAL); }

"+="                    {  count(); /*printf("%s \t<--ADD_ASSIGN\n",yytext);*/ return(ADD_ASSIGN); }
"-="                    {  count(); /*printf("%s \t<--SUB_ASSIGN\n",yytext);*/ return(SUB_ASSIGN); }
"*="                    {  count(); /*printf("%s \t<--MUL_ASSIGN\n",yytext);*/ return(MUL_ASSIGN); }
"/="                    {  count(); /*printf("%s \t<--DIV_ASSIGN\n",yytext);*/ return(DIV_ASSIGN); }
"%="                    {  count(); /*printf("%s \t<--MOD_ASSIGN\n",yytext);*/ return(MOD_ASSIGN); }
"&="                    {  count(); /*printf("%s \t<--AND_ASSIGN\n",yytext);*/ return(AND_ASSIGN); }
"^="                    {  count(); /*printf("%s \t<--XOR_ASSIGN\n",yytext);*/ return(XOR_ASSIGN); }
"|="                    {  count(); /*printf("%s \t<--OR_ASSIGN\n",yytext);*/ return(OR_ASSIGN); }
"++"                    {  count(); /*printf("%s \t<--INC_OP\n",yytext);*/ return(INC_OP); }
"--"                    {  count(); /*printf("%s \t<--DEC_OP\n",yytext);*/ return(DEC_OP); }
"->"                    {  count(); /*printf("%s \t<--PTR_OP\n",yytext);*/ return(PTR_OP); }
"&&"                    {  count(); /*printf("%s \t<--AND_OP\n",yytext);*/ return(AND_OP); }
"||"                    {  count(); /*printf("%s \t<--OR_OP\n",yytext);*/ return(OR_OP); }
"<="                    {  count(); /*printf("%s \t<--LE_OP\n",yytext);*/ return(LE_OP); }
">="                    {  count(); /*printf("%s \t<--GE_OP\n",yytext);*/ return(GE_OP); }
"=="                    {  count(); /*printf("%s \t<--EQ_OP\n",yytext);*/ return(EQ_OP); }
"!="                    {  count(); /*printf("%s \t<--NE_OP\n",yytext);*/ return(NE_OP); }

[\;\{\},\:\=\(\)\[\]\.\&\!\-\+\*\/\%\<\>\^\|\?]    {count();  return yytext[0];}

[ \t\v\f]            { ; }
\n                   { line_no++; }

.                    { printf("%s <--Unmatched character(s)\n",yytext);exit(1);}




%%
/*
int yywrap(){
    return 1;
}
*/
void comment(void)
{
    char c, prev = 0;
 
    while ((c = input()) != 0)          /* (EOF maps to 0) */
    {
            if (c == '/' && prev == '*')
                    return;
            prev = c;
    }
    printf("ERROR>> unterminated comment!\n");
}

int column = 0;

void count(void)
{
    int i;

    for (i = 0; yytext[i] != '\0'; i++)
        if (yytext[i] == '\n')
            column = 0;
        else if (yytext[i] == '\t')
            column += 8 - (column % 8);
        else
            column++;

    
}

