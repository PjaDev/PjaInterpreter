#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"
#include "parser.h"
#include "environment.h"

void init_bytecode(Bytecode *bytecode) {
    bytecode->instructions = NULL;
    bytecode->constants = NULL;
    bytecode->instruction_count = 0;
    bytecode->constant_count = 0;
}

void add_instruction(Bytecode *bytecode, BytecodeInstruction instruction) {
    bytecode->instructions = realloc(bytecode->instructions, sizeof(BytecodeInstruction) * (bytecode->instruction_count + 1));
    bytecode->instructions[bytecode->instruction_count++] = instruction;
}

int add_constant(Bytecode *bytecode, int value) {
    bytecode->constants = realloc(bytecode->constants, sizeof(int) * (bytecode->constant_count + 1));
    bytecode->constants[bytecode->constant_count] = value;
    return bytecode->constant_count++;
}

void compile_ast(Node *node, Bytecode *bytecode) {
    if (!node) return;

    switch (node->type) {
        case NODE_CONST:
            add_instruction(bytecode, BC_LOAD_CONST);
            add_constant(bytecode, node->int_value);
            break;
        case NODE_VAR:
            add_instruction(bytecode, BC_LOAD_VAR);
            break;
        case NODE_ASSIGN:
            compile_ast(node->right, bytecode);
            add_instruction(bytecode, BC_STORE_VAR);
            break;
        case NODE_ADD:
            compile_ast(node->left, bytecode);
            compile_ast(node->right, bytecode);
            add_instruction(bytecode, BC_ADD);
            break;
        case NODE_SUB:
            compile_ast(node->left, bytecode);
            compile_ast(node->right, bytecode);
            add_instruction(bytecode, BC_SUB);
            break;
        case NODE_MUL:
            compile_ast(node->left, bytecode);
            compile_ast(node->right, bytecode);
            add_instruction(bytecode, BC_MUL);
            break;
        case NODE_DIV:
            compile_ast(node->left, bytecode);
            compile_ast(node->right, bytecode);
            add_instruction(bytecode, BC_DIV);
            break;
    }
}

void free_bytecode(Bytecode *bytecode) {
    free(bytecode->instructions);
    free(bytecode->constants);
}

void compile(const char *filename, Bytecode *bytecode) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    // Inisialisasi bytecode
    init_bytecode(bytecode);

    // Parsing AST dan kompilasi (ini contoh dummy)
    Node *ast = parse(file);
    compile_ast(ast, bytecode);

    // Bebaskan AST jika diperlukan (tidak diimplementasikan di sini)

    fclose(file);
}
