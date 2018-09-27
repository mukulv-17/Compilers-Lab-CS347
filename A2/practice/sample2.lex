/* 
 * Sample Scanner2: 
 * Description: Count the number of characters and the number of lines 
 *              from standard input
 * Usage: (1) $ flex sample2.lex
 *        (2) $ gcc lex.yy.c -lfl
 *        (3) $ ./a.out
 *        stdin> whatever you like
 *	      stdin> Ctrl-D
 * Questions: Is it ok if we do not indent the first line?
 *            What will happen if we remove the second rule?
 */
%{
//Indentation matters below, or include the code in these tags <<- Because indented text is copied as is to the c file 
int num_chars = 0;
%}

	int num_lines = 0;

%%

\n	++num_lines; ++num_chars;
.	++num_chars;

%%

void main()
{
  yylex();
  printf("# of lines = %d, # of chars = %d\n", num_lines, num_chars);
}

