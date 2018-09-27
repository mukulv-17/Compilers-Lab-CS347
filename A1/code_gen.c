#include <stdio.h>
#include "lex.h"

char    *factor     ( void );
char    *term       ( void );
char    *expression ( void );

extern char *newname( void       );
extern void freename( char *name );
extern FILE* codegen_out;

//debug utility
int DEBUG_MODE=1;
#define dprintf(...) if(DEBUG_MODE)printf(__VA_ARGS__);

int tabs=0;

indent(){
    int i1;
    for( i1=1;i1<=tabs;i1++)
        fprintf(codegen_out,"    ");
}

statements()
{
    /*  
       statements -> expression SEMI  |  
    RR expression SEMI statements  
    */
    dprintf("statement : %s\n",yytext);
    char *tempvar,*yytext_temp;
    int yyleng_temp;
    
    if( match( ID ) ){
        yyleng_temp=yyleng;
        yytext_temp=yytext;//copying the id name
        /*        Done - TODO: make complex expression test */
        advance();
        if( match( ASSIGN ) )// The colon
        {
            advance();
            if( match(COMP) )// The '='
            {
                advance();
                tempvar=expression();//The tempname which is storing the value of the expression
                //print the assignment
                indent(); 
                fprintf(codegen_out," _%0.*s := %s \n", yyleng_temp, yytext_temp,tempvar );
                if( match(SEMI) )
                    advance();
                else{
                    fprintf( stderr, "Line %d: Syntax error: Expected ';', inserting automatically.\n", yylineno);
                    exit(1);
                }
                freename( tempvar );
            }
            else{
                fprintf( stderr, "Line %d: Syntax error: missing '=' after ':', continuing.\n", yylineno );
                exit(1);
            }
        }
        else{
            fprintf( stderr, "Line %d: Expected := after ID '%s' \n", yylineno, yytext_temp);    
            exit(1);
        }
    }
    else if( match( IF ) )
    {
        advance();
        
        tempvar=expression();
        indent();
        fprintf(codegen_out," if ( %s ) \n", tempvar);
        if( match( THEN ) )
        {
            //-----------------------------
            indent();
            fprintf(codegen_out," then beginIf \n");
            //------------------------------
            tabs++;
            advance();
            if( !match(EOI) )
                statements();
            tabs--;
            indent();
            fprintf(codegen_out," endIf \n");
        }
        else{
            fprintf( stderr, "Line %d: missing 'then' after 'if' \n", yylineno );
            exit(1);
        }
        freename( tempvar );
    }
    
    
    else if( match(WHILE) )
    {
        advance();
        indent();
        fprintf(codegen_out," COND \n");
        tempvar=expression();
        indent();
        fprintf(codegen_out," while ( %s ) \n", tempvar);
        if( match( DO ) )
        {
            indent();
            fprintf(codegen_out," do beginWhile \n");
            tabs++;
            advance();
            if( !match(EOI) )
                statements();
            tabs--;
            indent();
            fprintf(codegen_out," endWhile \n");
        }
        else{
            fprintf( stderr, "Line %d: missing 'DO' after 'WHILE' \n", yylineno );
            exit(1);
        }
        freename( tempvar );
    }
    
    else if( match(BEGIN) )
    {
        indent();
        fprintf(codegen_out," begin \n");
        tabs++;
        advance();
        if( !match(EOI) )
            opt_stmts();
        tabs--;
        if( match( END ) )
        {   
            indent();
            fprintf(codegen_out," end \n");
            advance(); 
        }
        else{
            fprintf( stderr, "Line %d: missing 'END' \n", yylineno );
            exit(1);
        }
    }
    
    else
    {
        //show error and skip the current lexeme
        fprintf( stderr, "Line %d: No token matched from ID/if/while/begin \n", yylineno );
        exit(1);
        // advance();
    }
    dprintf("\n");    
}


opt_stmts()
{
    /*
        To handle begin and end.
        opt_stmts → stmt_list |є
    */
    // dprintf("opt_stmts : %s\n",yytext);
    if(!match(END))
        stmt_list();
    
}

stmt_list()
{
    // dprintf("stmt_list : %s\n",yytext);

    /*
    RR  stmt_list → stmt; stmt_list | stmt
    */

    statements();
    if(!match(END))
        stmt_list();
}

char    *expression()
{
    // dprintf("expression : %s\n",yytext);


    // TODO: make test case to check epsilon.
    /* expression  -> term expression'
    RR expression' -> OPERATOR expression |  epsilon
     */

    char  *tempvar, *tempvar2;

    dprintf("expr->(term");
    tempvar = term();
    dprintf(")");
    while(1)
    {
        char* symbol;
        if( match( PLUS ) ){
          symbol="+=";
          dprintf("+");

      }   
      else if( match( MINUS ) )   symbol="-=";
      else if( match( LT ) )      symbol="<";
      else if( match( GT ) )      symbol=">";
      else if( match( COMP ) )    symbol="==";
        else break; // expression' -> epsilon. 
        advance();
        dprintf("(term");
        tempvar2 = term();
        dprintf(")");
        indent();
        // term OP expression
        fprintf(codegen_out,"%s %s %s \n", tempvar, symbol, tempvar2 );
        freename( tempvar2 );
    }
    return tempvar;
}

char    *term()
{
    // dprintf("term : %s\n",yytext);

    /*
    term -> factor OP' term | epsilon
    */

    char  *tempvar, *tempvar2 ;

    dprintf("->(factor->");
    tempvar = factor();
    dprintf(")");
    while( 1 )
    {
        char* symbol;
        if(match(TIMES)){
            dprintf("*");
          symbol="*=";
      }   
      else if(match(DIV))     symbol="/=";
      else break;
      advance();
      dprintf("(factor->");
        tempvar2 = factor();//  generate a new tempvar by default on matching num_or_id
        dprintf(")");
        indent();
        fprintf(codegen_out,"%s %s %s \n", tempvar, symbol, tempvar2 );
        freename( tempvar2 );

    }

    return tempvar;
}

char    *factor()
{
    // dprintf("factor : %s\n",yytext);

    char *tempvar;
     // Done - TODO: test to check brackets matching

    /* Print the assignment instruction. The %0.*s conversion is a form of
     * %X.Ys, where X is the field width and Y is the maximum number of
     * characters that will be printed (even if the string is longer). I'm
     * using the %0.*s to print the string because it's not \0 terminated.
     * The field has a default width of 0, but it will grow the size needed
     * to print the string. The ".*" tells printf() to take the maximum-
     * number-of-characters count from the next argument (yyleng).
             ALTERNATIVE-
        yytext_temp = (char*) malloc( sizeof(yytext) + 1);
        yytext_temp = yytext;
        yytext_temp[sizeof(yytext)] = '\0';

    */

     /*
        factor -> num_or_id | LP expression RP
     */
    
    if( match(NUM))
    {
        indent();
        fprintf(codegen_out,"%s := %0.*s \n", tempvar = newname(), yyleng, yytext );
        dprintf("%0.*s",yyleng,yytext);
        advance();
    }
    else if( match(ID) )
    {       
        indent();
        fprintf(codegen_out,"%s := _%0.*s \n", tempvar = newname(), yyleng, yytext );
        dprintf("%0.*s",yyleng,yytext);
        advance();
    }
    else if( match(LP) )
    {
        advance();
        
        tempvar = expression();

        if( match(RP) )
            advance();
        else{
            fprintf(stderr, "Line %d: Mismatching parentheses, exiting now.\n", yylineno );
            exit(1);
        }
    }
    else{
        fprintf( stderr, "Line %d: No token match from NUMBER/ID, exiting now.\n", yylineno );
        exit(1);
    }

    return tempvar;
}