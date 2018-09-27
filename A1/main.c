#include <stdio.h>

FILE* codegen_in, *codegen_out;
int main(int argc, char* argv[])
{
	if(argc==3){
		char const* const inFileName = argv[1];
		char const* const outFileName = argv[2];
		codegen_in = fopen(inFileName, "r");
		codegen_out = fopen(outFileName, "w+");

		statements ();
	}
	else{
		printf("Give two arguments - inFile, outFile");
	}
}
