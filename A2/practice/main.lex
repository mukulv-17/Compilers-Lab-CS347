%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void comment(void);

%}

D            [0-9]
L            [a-zA-Z_]

%%
"/*"            { comment(); }
" //".*$                { /* eat single line comments */}

"break"            { ECHO; printf("\t<--BREAK\n"); }
"char"            { ECHO; printf("\t<--CHAR\n"); }
"const"            { ECHO; printf("\t<--CONST\n"); }
"continue"        { ECHO; printf("\t<--CONTINUE\n"); }
"do"            { ECHO; printf("\t<--DO\n"); }
"double"        { ECHO; printf("\t<--DOUBLE\n"); }
"else"            { ECHO; printf("\t<--ELSE\n"); }
"float"            { ECHO; printf("\t<--FLOAT\n"); }
"for"            { ECHO; printf("\t<--FOR\n"); }
"if"            { ECHO; printf("\t<--IF\n"); }
"int"            { ECHO; printf("\t<--INT\n"); }
"long"            { ECHO; printf("\t<--LONG\n"); }
"return"        { ECHO; printf("\t<--RETURN\n"); }
"short"            { ECHO; printf("\t<--SHORT\n"); }
"signed"        { ECHO; printf("\t<--SIGNED\n"); }
"unsigned"        { ECHO; printf("\t<--UNSIGNED\n"); }
"while"            { ECHO; printf("\t<--WHILE\n"); }
    
    /*------------------extended language keywords----------*/
name                {ECHO; printf("\t<--P_NAME\n");}

    /*--------------------------PROCESSOR CLASS----------------------------*/
Processor            {ECHO; printf("\t<--C_PROC\n");}
isa                    {ECHO; printf("\t<--P_ISA\n");}    
clock_speed            {ECHO; printf("\t<--P_CLOCK_SPEED\n");}
l1_memory        {ECHO; printf("\t<--P_MEM_OBJ_1\n");}
l2_memory        {ECHO; printf("\t<--P_MEM_OBJ_2\n");}

is_running            {ECHO; printf("\t<--MF_IS_RUNNING\n");}
submit_jobs            {ECHO; printf("\t<--MF_SUBMIT_JOBS\n");}
get_clock_speed        {ECHO; printf("\t<--MF_GET_CS\n");}
run                  {ECHO; printf("\t<--MF_RUN\n");}
discard_job            {ECHO; printf("\t<--MF_DISCARD_JOB\n");}

    /*---------------------LINK CLASS ------------------------*/
Link                {ECHO; printf("\t<--C_LINK\n");}
start_point         {ECHO; printf("\t<--P_START_POINT\n");}
end_point             {ECHO; printf("\t<--P_END_POINT\n");}
bandwidth             {ECHO; printf("\t<--P_BANDWIDTH\n");}
channel_capacity     {ECHO; printf("\t<--P_CHANNEL_CAP\n");}
    
    /*--------------------MEMORY CLASS-------------------*/
Memory                 {ECHO; printf("\t<--C_Memory\n");}
memory_type            {ECHO; printf("\t<--P_MEM_TYPE\n");}
mem_size             {ECHO; printf("\t<--P_MEM_SIZE\n");}

    /*--------------------JOB CLASS---------------------*/
Job                 {ECHO; printf("\t<--C_JOB\n");}
job_id                {ECHO; printf("\t<--P_JOB_ID\n");}
flops_required        {ECHO; printf("\t<--P_FLOPS_REQ\n");}
deadline            {ECHO; printf("\t<--P_DEADLINE\n");}
mem_required        {ECHO; printf("\t<--P_MEM_REQ\n");}
affinity            {ECHO; printf("\t<--P_AFFINITY\n");}

get_memory            {ECHO; printf("\t<--MF_GET_MEMORY\n");}

    /*---------------CLUSTER CLASS----------------*/
Cluster             {ECHO; printf("\t<--C_CLUSTER\n");}
processors            {ECHO; printf("\t<--P_PROCESSORS\n");}    
topology            {ECHO; printf("\t<--C_TOPOLOGY\n");}
link_bandwidth        {ECHO; printf("\t<--C_LINK_BANDW\n");}
link_capacity        {ECHO; printf("\t<--C_LINK_CAP\n");}

{L}({L}|{D})*        { ECHO; printf("\t<--IDENTIFIER\n"); }

{D}+        { ECHO; printf("\t<--INTEGER\n"); }
({D}+"."{D}*)|({D}*"."{D}+)        { ECHO; printf("\t<--FLOAT\n"); }

L?\"(\\.|[^\\"\n])*\"    { ECHO; printf("\t<--STRING_LITERAL\n"); }
L?\'(\\.|[^\\'\n])*\'    { ECHO; printf("\t<--STRING_LITERAL\n"); }

"+="            { ECHO; printf("\t<--ADD_ASSIGN\n"); }
"-="            { ECHO; printf("\t<--SUB_ASSIGN\n"); }
"*="            { ECHO; printf("\t<--MUL_ASSIGN\n"); }
"/="            { ECHO; printf("\t<--DIV_ASSIGN\n"); }
"%="            { ECHO; printf("\t<--MOD_ASSIGN\n"); }
"&="            { ECHO; printf("\t<--AND_ASSIGN\n"); }
"^="            { ECHO; printf("\t<--XOR_ASSIGN\n"); }
"|="            { ECHO; printf("\t<--OR_ASSIGN\n"); }
"++"            { ECHO; printf("\t<--INC_OP\n"); }
"--"            { ECHO; printf("\t<--DEC_OP\n"); }
"->"            { ECHO; printf("\t<--PTR_OP\n"); }
"&&"            { ECHO; printf("\t<--AND_OP\n"); }
"||"            { ECHO; printf("\t<--OR_OP\n"); }
"<="            { ECHO; printf("\t<--LE_OP\n"); }
">="            { ECHO; printf("\t<--GE_OP\n"); }
"=="            { ECHO; printf("\t<--EQ_OP\n"); }
"!="            { ECHO; printf("\t<--NE_OP\n"); }
";"            { ECHO; printf("\t<--SEMICOLON\n"); }
"{"            { ECHO; printf("\t<--LCB\n"); /*LEFT CURLY BRACKETS*/}
"}"            { ECHO; printf("\t<--RCB\n"); }
","            { ECHO; printf("\t<--COMMA\n"); }
":"            { ECHO; printf("\t<--COLON\n"); }
"="            { ECHO; printf("\t<--ASSIGN\n"); }
"("            { ECHO; printf("\t<--LP\n"); }
")"            { ECHO; printf("\t<--RP\n"); }
"["            { ECHO; printf("\t<--LSB\n"); /*LEFT SQUARE BRACKETS*/}
"]"            { ECHO; printf("\t<--RSB\n"); }
"."            { ECHO; printf("\t<--DOT\n"); }
"&"            { ECHO; printf("\t<--BIT_AND\n"); }
"-"            { ECHO; printf("\t<--MINUS\n"); }
"+"            { ECHO; printf("\t<--PLUS\n"); }
"*"            { ECHO; printf("\t<--TIMES\n"); }
"/"            { ECHO; printf("\t<--DIV\n"); }
"%"            { ECHO; printf("\t<--PERCENT\n"); }
"<"            { ECHO; printf("\t<--LT\n"); }
">"            { ECHO; printf("\t<--GT\n"); }
"^"            { ECHO; printf("\t<--CARET\n"); }
"|"            { ECHO; printf("\t<--BIT_OR\n"); }

[ \t\v\n\f]        { ; }
.            { printf("%s <--Unmatched character(s)\n",yytext);}



%%

void comment(void)
{
    char c, prev = 0;
 
    while ((c = input()) != 0)      /* (EOF maps to 0) */
    {
        if (c == '/' && prev == '*')
            return;
        prev = c;
    }
    printf("ERROR>> unterminated comment!\n");
}
