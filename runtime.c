#include <stdio.h>
#include "runtime.h"

void execute_bytecode(Bytecode *bytecode, Environment *env) {
    int pc = 0; // Program counter
    int stack[256];
    int sp = -1; // Stack pointer

    while (pc < bytecode->instruction_count) {
        switch (bytecode->instructions[pc]) {
            case BC_LOAD_CONST:
                stack[++sp] = bytecode->constants[pc++];
                break;
            case BC_ADD:
                stack[sp-1] = stack[sp-1] + stack[sp];
                sp--;
                pc++;
                break;
            case BC_SUB:
                stack[sp-1] = stack[sp-1] - stack[sp];
                sp--;
                pc++;
                break;
            case BC_MUL:
                stack[sp-1] = stack[sp-1] * stack[sp];
                sp--;
                pc++;
                break;
            case BC_DIV:
                stack[sp-1] = stack[sp-1] / stack[sp];
                sp--;
                pc++;
                break;
            case BC_STORE_VAR:
                add_variable(env, "var", stack[sp--]);
                pc++;
                break;
            case BC_LOAD_VAR:
                stack[++sp] = get_variable(env, "var");
                pc++;
                break;
            case BC_PRINT:
                printf("%d\n", stack[sp--]);
                pc++;
                break;
            case BC_END:
                return;
        }
    }
}
