#ifndef __RV32I_INSTRUCTIONS_H__
#define __RV32I_INSTRUCTIONS_H__

#include <stdint.h>


/* RV32I base Instruction Set
 *
 * R-type funct7   | rs2 | rs1 | funct3 | rd       | opcode
 * I-type imm[11:0]      | rs1 | funct3 | rd       | opcode
 * S-type imm[11:5]| rs2 | rs1 | funct3 | imm[4:0] | opcode
 * B-type imm[xxx] | rs2 | rs1 | funct3 | imm[xxx] | opcode
 * U-type imm[31:12]                    | rd       | opcode
 * J-type imm[xxx]                      | rd       | opcode
 */

/*
 * Opcodes
 */
struct opcode {
    char     *name;
    uint32_t val;
};


#define OP_CODE(n, v) { #n, v},

struct opcode op_code[] = {
#include "opcode_defs.h"
};

/* Instructions */

struct instruction {
    char *name;
    int  nfields;
    char format;
    char *opcode;
    uint32_t funct3;
    uint32_t funct7;
};


struct instruction instruction[] = {
#include "instruction_defs.h"
};

#endif
