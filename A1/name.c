#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
// Note - Atmost 10 temp variables supported now in assembly code generation
char  *Names[] = { "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7" };   
char  **Namep  = Names;  // the temp names stack pointer i.e. last used temp name
// sizeof(Names)/sizeof(Names[0]); ==== sizeof(a)/sizeof(a[0]); == numTerms
char **lastNameAddr = &Names[ sizeof(Names)/sizeof(Names[0]) ];

char  *newname()   
{   
    if( Namep >= lastNameAddr )   
    {   
        fprintf( stderr, "%d: Expression too complex\n", yylineno );   
        exit( 1 );   
    }   
   
    return( *Namep++ );   
}   
   
freename(char    *s)  // argument of this will be an address of element of Names array
{   
    if( Namep > &Names[0] )   
        *--Namep = s;   
    else   
        fprintf(stderr, "%d: (Internal error) Name stack underflow\n", yylineno );   
}   
