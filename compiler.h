#ifndef COMPILER_H
#define COMPILER_H

#include "ast.h"

typedef enum {
    BC_LOAD_CONST,
    BC_ADD,
    BC_SUB,
    BC_MUL,
    BC_DIV,
    BC_STORE_VAR,
    BC_LOAD_VAR,
    BC_PRINT,
    BC_END
} BytecodeInstruction;

typedef struct {
    BytecodeInstruction *instructions;
    int *constants;
    int instruction_count;
    int constant_count;
} Bytecode;

void init_bytecode(Bytecode *bytecode);
void compile_ast(Node *node, Bytecode *bytecode);
void free_bytecode(Bytecode *bytecode);

#endif
