/*
Consider the following problem: copy the input to the output, changing the word magic to first on every line which began with the letter a, changing magic to second on every line which began with the letter b, and changing magic to third on every line which began with the letter c. All other words and all other lines are left unchanged.

Doing this with states
*/
%START AA BB CC
/* This option should be removed when inputting it to a parser generator such as yacc */
%option noyywrap
%%
^a	{ECHO; BEGIN AA;}
^b	{ECHO; BEGIN BB;}
^c	{ECHO; BEGIN CC;}
\n	{ECHO; BEGIN 0;}
<AA>magic	printf("first");
<BB>magic	printf("second");
<CC>magic	printf("third");
