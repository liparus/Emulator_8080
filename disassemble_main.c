//
//
// Disassemble main routine
// ************************
//
// 1. Opens up a file full of compiled 8080 code
// 2. Reads into a memory buffer
// 3. Skips through the memory buffer calling Disassemble8080op
// 4. Advance the PC by the amount returned by Disassemble8080op
// 5. Quit at the end of the buffer
//

#include<stdio.h>
#include<stdlib.h>
#include "Disassemble8080op.h"


int main(int argc, char**argv) {
	
	FILE *f = fopen(argv[1], "rb");

	if (f==NULL) {
		printf("error: Could not open %s\n", argv[1]);
		exit(1);
	}

	// Get the file size and read it into a memory buffer
	fseek(f, 0L, SEEK_END);
	int fsize = ftell(f);
	fseek(f, 0L, SEEK_SET);

	unsigned char *buffer = malloc(fsize);

	fread(buffer, fsize, 1, f);
	fclose(f);

	int pc = 0;

	while (pc < fsize) {
		pc += Disassemble8080op(buffer, pc);
		}

	return 0;

}
