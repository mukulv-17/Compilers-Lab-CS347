test=test1.txt
intermediate=intermediate_out.txt
# SelfNote: The target is supposed to be a filename, it's not a label!
code_gen: name.c lex.c code_gen.c main.c 
	gcc -w -o code_gen name.c lex.c code_gen.c main.c

asm_gen: name.c lex.c asm_gen.c
	gcc -w -o asm_gen name.c lex.c asm_gen.c

clean: code_gen
	rm code_gen

clean_all: asm_gen code_gen
	rm code_gen asm_gen

run: code_gen
	./code_gen $(test) $(intermediate)

run_asm: asm_gen
	./asm_gen $(intermediate)