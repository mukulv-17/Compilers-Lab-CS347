%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum tokenClass{ STRING_LITERAL  };
%}
    /* %x ensures exclusivity, but still It's a good practice to write <INITIAL> before the patterns having no start conditions for readability*/
%x InQuoteSGL InQuoteDBL INCOMMENT
D           [0-9]
L           [a-zA-Z_]

%%

<INITIAL>\"             { BEGIN(InQuoteDBL); }
<InQuoteDBL>{
    /*Here, it's hard to print now. Things that matter inside here are - Closing quote, Escaped quote*/
\\\"              { /*Escaped double quote*/ }
\"              { BEGIN(INITIAL); }
.|\n            { /* Inside double quote stuff */ }
}
.   {/*Do not echo other stuff*/}

%%

