%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum tokenClass{ STRING_LITERAL  };
%}

L           [a-zA-Z_]
%%
L?\"(\\.|[^\\"])*\"   { printf(">>%s<< : STRING_LITERAL \n",yytext); /* Multi-line string matchr */}
.   {/*Do not echo other stuff*/}
%%

