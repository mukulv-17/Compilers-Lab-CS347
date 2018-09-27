Commands to compile -
1. gcc -o code_gen name.c lex.c code_gen.c main.c
2. gcc -o asm_gen name.c lex.c asm_gen.c main.c

Commands to run test-
1. code_gen < test1.txt > intermediate_out.txt
2. asm_gen intermediate_out.txt

Alternatively you can use make -
make code_gen
make run test=test1.txt
make asm_gen
make run_asm intermediate=intermediate_out.txt

Make for windows-
http://gnuwin32.sourceforge.net/packages/make.htm