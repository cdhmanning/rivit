#include <stdio.h>

#include "rv32i_instructions.h"


void gen_opcodes(void)
{
	int i;
	int n = sizeof op_code/sizeof(op_code[0]);

	for (i = 0; i < n; i++) {
		struct opcode *oc = &op_code[i];
		printf("#define %-10s 0x%02x\n",
				oc->name,
				oc->val);
	}
}

void gen_defs(void)
{
	int i;
	int n = sizeof instruction/sizeof(instruction[0]);

	for (i = 0; i < n; i++) {
		struct instruction *id = &instruction[i];

		printf("/*%-6s %c-type opcode=%-10s",
				id->name,
				id->format,
				id->opcode);

		if (id->nfields >= 2)
			printf(" func3=0x%02x",
				id->funct3);

		if (id->nfields >= 3)
			printf(" funct7=0x%02x",
				id->funct7);
		printf(" */\n");


		if (id->nfields >= 2)
			printf("#define F3_%s 0x%02x\n",
				id->name,
				id->funct3);
		if (id->nfields >= 3)
			printf("#define F7_%s 0x%02x\n",
				id->name,
				id->funct7);
	}
}

int main(int argc, char *argv[])
{
	gen_opcodes();
	gen_defs();
}
