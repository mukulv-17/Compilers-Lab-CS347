/*
EOI	 =  End of input         
SEMI	 =  ;                
PLUS	 =  +                
TIMES =  *                
LP	 =  (                
RP	 =  )                
NUM	 =  Decimal Number  
MINUS =   -   
DIV	 =   /   
LT	 =   <   
GT	 =  >   
ASSIGN =  :   
COMP	 =  =   
IF	 =  if      
THEN	 = then 
WHILE = while 
DO	 = do 
BEGIN = begin 
END	 = end 
ID	 = identifier 
*/
enum {EOI, SEMI, PLUS, TIMES, LP, RP, NUM, MINUS, 
	DIV, LT, GT, ASSIGN, COMP, IF, THEN, WHILE, DO, BEGIN, END, ID};

extern char *yytext;        /* in lex.c         */
extern int yyleng;
extern int yylineno;
