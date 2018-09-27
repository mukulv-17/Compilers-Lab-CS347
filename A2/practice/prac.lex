/*
Config processor
NOTE: \d, \w do not work here.
Use expressions
[:alnum:] [:alpha:] [:blank:]
[:cntrl:] [:digit:] [:graph:]
[:lower:] [:print:] [:punct:]
[:space:] [:upper:] [:xdigit:]
*/
%{
#include "myscanner.h"
	int my_yylineno=1;
%}//
/* This option should be removed when inputting it to a parser generator such as yacc */
%option noyywrap

%%
":"								return COLON;
"db_type"						return TYPE;
"db_name"						return NAME;
"db_table_prefix"				return TABLE_PREFIX;
"db_port"						return PORT;
[[:digit:]]+					return INTEGER;
[[:alpha:]][[:alnum:]_]*		return IDENTIFIER;
\n 								{my_yylineno++;}
[ \t\n]+          	;//printf("<Whitespace>\n");
.					printf("Error: unexpected character '%s', discarding.(Panic mode)\n",yytext);
%%

int printSyntaxErr(char* expected){
	printf("Syntax Error, expected %s, found '%s' at line number %d\n",expected,yytext,my_yylineno);
	return 1;
}

void advance(int * tokenvar){
	*tokenvar = yylex();
	printf("Line %d) %s = %s (%d)\n",my_yylineno, yytext, names[*tokenvar],*tokenvar);
}
int main( int argc,char * argv[]){	
	++argv, --argc;//skip to filename
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
	int ntoken=1, vtoken=0;
	// printf("%s%d\n",names[0],vtoken);
	// printf(" %s\n",names[0]);
	// printf("%s\n",names[0]);// GCC optimizes exactly this format string into puts,

	// Parsing part can go here -
	// ntoken = yylex();
	// while(ntoken){
	// 	// Parsing part can go here -
	// 	printf("%d : %s\n", ntoken,names[ntoken]);
	// 	ntoken = yylex();
	// }
	advance(&ntoken); //key
	while(ntoken){
		if(yylex() != COLON)
			return printSyntaxErr("a ':'");
		
		advance(&vtoken); //value
		// enum {ZERONULL,TYPE,NAME,TABLE_PREFIX,PORT,COLON,IDENTIFIER,INTEGER};
		switch(ntoken){
			case TYPE:
			case NAME: 
			case TABLE_PREFIX: 
			if(vtoken!=IDENTIFIER)
				return printSyntaxErr("an Identifer");
			else
				printf("%s is set to %s\n",names[ntoken],yytext);
			break;
			case PORT: 
			if(vtoken!=INTEGER)
				return printSyntaxErr("an Integer");
			// else
			// 	printf("%s is set to %s\n",names[ntoken],yytext);
			break;
			default: return printSyntaxErr("The unexpected");
		}
		advance(&ntoken); //next key
	}
}
