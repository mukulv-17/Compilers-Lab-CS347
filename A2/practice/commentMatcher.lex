%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum tokenClass{ STRING_LITERAL };
%}
%x INCOMMENT
	/* The strings above denote just conditions */
%%
[ \r\t\v\f\n]*          { /* eat whitespace */ }
"//".*$                 { /* eat single line comments */ printf("singleCOMMENT>>%s<<\n",yytext);}
<INITIAL>"/*"           { BEGIN(INCOMMENT);printf("beginMultiCOMMENT>>"); /* eat multiline C comments */ }
<INCOMMENT>{
    [^*]*           	{ECHO;/* eat anything other than stars */ }
    "*"+[^/]*       	{ECHO;/* eat the stars without a matching '/' */ }
    "*"+"/"         	{ BEGIN(INITIAL); printf("<<endMultiCOMMENT\n"); }
}
.   {/*Do not echo other stuff*/}
%%

