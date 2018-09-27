%option noyywrap
    // %option yylineno
    //^ yylineno option makes it 'extern'able to bison, but the yylineno can sometimes be off DIV one
    
    //SelfNote for tokens: could've used [][=+*...]     return yytext[0]; and use the characters directly in grammar 
%{
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "functions2.cpp"
//#include "main.tab.h" // for YYTYPE, need to use -d option of bison to generate this.
#include "y.tab.h" // use -y option for this naming
using namespace std;

void comment(void);
void count(void);
int lineno=1;// still used for clarity
%}

CHARVAL ['][a-zA-Z0-9][']
D                    [0-9]
L                    [a-zA-Z_]


%%
"/*"                    { comment(); }
"//".*$                    { /* eat single line comments */}


"break"                    {  count();  yylval.Node=add_node_leaf("BREAK","break"); return(BREAK); }
"else"                    {  count();   yylval.Node=add_node_leaf("ELSE","else"); return(ELSE); }
"if"                    {  count();     yylval.Node=add_node_leaf("IF","if"); return(IF); }
"return"            {  count();     yylval.Node=add_node_leaf("RETURN","return"); return(RETURN); }
"while"                    {  count();  yylval.Node=add_node_leaf("WHILE","while"); return(WHILE); }

"int"               { yylval.Node = add_node_leaf("TYPE_SPECIFIER", "int", INT); return TYPE_SPECIFIER; }
"bool"              { yylval.Node = add_node_leaf("TYPE_SPECIFIER", "bool", BOOL); return TYPE_SPECIFIER; }
"char"              { yylval.Node = add_node_leaf("TYPE_SPECIFIER", "char", CHAR); return TYPE_SPECIFIER; }

"true"              { yylval.Node = add_node_leaf("BOOL_VAL","true"); return BOOL_VAL; }
"false"             { yylval.Node = add_node_leaf("BOOL_VAL","false"); return BOOL_VAL; }

{L}({L}|{D})*            {  count();    yylval.Node=add_node_leaf("IDENTIFIER",string(yytext)); return(IDENTIFIER); }
\-?{D}+            {  count();     yylval.Node=add_node_leaf("INTEGER",string(yytext)); return(INTEGER); }


L?\"(\\.|[^\\"\n])*\"    {  count();    yylval.Node=add_node_leaf("STRING_LITERAL",string(yytext)); return(STRING_LITERAL); }
{CHARVAL}               { count();  yylval.Node = add_node_leaf("CHARVAL", string(yytext)); return CHARVAL; }

"&&"                    {  count();     yylval.Node=add_node_leaf("AND_OP",string(yytext)); return(AND_OP); }
"||"                    {  count();     yylval.Node=add_node_leaf("OR_OP",string(yytext)); return(OR_OP); }
"<="                    {  count();     yylval.Node=add_node_leaf("LE_OP",string(yytext)); return(LE_OP); }
">="                    {  count();     yylval.Node=add_node_leaf("GE_OP",string(yytext)); return(GE_OP); }
"=="                    {  count();     yylval.Node=add_node_leaf("EQ_OP",string(yytext)); return(EQ_OP); }
"!="                    {  count();     yylval.Node=add_node_leaf("NE_OP",string(yytext)); return(NE_OP); }
"++"                    {  count();     yylval.Node=add_node_leaf("INC_OP",string(yytext)); return(INC_OP); }
"--"                    {  count();     yylval.Node=add_node_leaf("DEC_OP",string(yytext)); return(DEC_OP); }
"("                     {  count();     yylval.Node=add_node_leaf("ORB",string(yytext)); return(ORB); }
")"                     {  count();     yylval.Node=add_node_leaf("CRB",string(yytext)); return(CRB); }
"["                     {  count();     yylval.Node=add_node_leaf("OSB",string(yytext)); return(OSB); }
"]"                     {  count();     yylval.Node=add_node_leaf("CSB",string(yytext)); return(CSB); }
"{"                     {  count();     yylval.Node=add_node_leaf("OCB",string(yytext)); return(OCB); }
"}"                     {  count();     yylval.Node=add_node_leaf("CCB",string(yytext)); return(CCB); }
"+"                 { yylval.Node = add_node_leaf("PLUS",string(yytext)); return PLUS; }
"-"                 { yylval.Node = add_node_leaf("MINUS",string(yytext)); return MINUS; }
"/"                 { yylval.Node = add_node_leaf("DIV",string(yytext)); return DIV; }
"*"                 { yylval.Node = add_node_leaf("TIMES",string(yytext)); return TIMES; }
"="                 { yylval.Node = add_node_leaf("ASSIGN",string(yytext)); return ASSIGN; }
"&"                 { yylval.Node = add_node_leaf("AND",string(yytext)); return AND; }
"|"                 { yylval.Node = add_node_leaf("OR",string(yytext)); return OR; }
"!"                 { yylval.Node = add_node_leaf("NOT",string(yytext)); return NOT; }
">"                 { yylval.Node = add_node_leaf("GREATER",string(yytext)); return GREATER; }
"<"                 { yylval.Node = add_node_leaf("LESS",string(yytext)); return LESS; }
"%"                 { yylval.Node = add_node_leaf("MOD",string(yytext)); return MOD; }
","                 { yylval.Node = add_node_leaf("COMMA",string(yytext)); return COMMA; }
";"                 { yylval.Node = add_node_leaf("SEMICOLON",string(yytext)); return SEMICOLON; }

[ \t\v\f]            { ; }
\n                   { lineno++; }

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
 
    while ((c = yyinput()) != 0)          /* (EOF maps to 0) */
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

