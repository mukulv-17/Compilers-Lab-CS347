/*
Consider the following problem: copy the input to the output, changing the word magic to first on every line which began with the letter a, changing magic to second on every line which began with the letter b, and changing magic to third on every line which began with the letter c. All other words and all other lines are left unchanged.

These rules are so simple that the easiest way to do this job is with a flag:

Note: 
ECHO is predefined in flex as -
#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )
	*/
/* This option should be removed when inputting it to a parser generator such as yacc */
%option noyywrap

%{
int flag;
%}

%%
^a	{flag = 'a'; ECHO;}
^b	{flag = 'b'; ECHO;}
^c	{flag = 'c'; ECHO;}
\n	{flag =  0 ; ECHO;}
magic	{
	switch (flag)
	{
		case 'a': printf("first"); break;
		case 'b': printf("second"); break;
		case 'c': printf("third"); break;
		default: ECHO; break;
	}
}