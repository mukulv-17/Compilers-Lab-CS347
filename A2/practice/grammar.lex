%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum tokenClass{ STRING_LITERAL,  };

%}

%x InQuoteSGL InQuoteDBL INCOMMENT
    /* %x ensures exclusivity, but still It's a good practice to write <INITIAL> before the patterns having no start conditions for readability*/
D           [0-9]
L           [a-zA-Z_]

%%
    /* DOS escapes = Formfeed (\f) and vertical tab (\v)*/
[ \r\t\v\f\n]*          { /* eat whitespace */ }
"//".*$                 { /* eat single line comments */ printf("singleCOMMENT>>%s<<\n",yytext);}

<INITIAL>"/*"           { BEGIN(INCOMMENT);printf("beginMultiCOMMENT>>"); /* eat multiline C comments */ }
<INCOMMENT>{
    [^*]*               {ECHO;/* eat anything other than stars */ }
    "*"+[^/]*           {ECHO;/* eat the stars without a matching '/' */ }
    "*"+"/"             { BEGIN(INITIAL); printf("<<endMultiCOMMENT\n"); }
}
L?\"(\\.|[^\\"])*\"   { printf("beginSTRING>>%s<<endSTRING\n",yytext); /* Multi-line string matchr */}
.   {/*Do not echo other stuff*/}
