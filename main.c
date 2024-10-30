#include <stdio.h>
#include "interpreter.h"
#include "compiler.h"
#include "runtime.h"
#include "environment.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Inisialisasi lingkungan
    Environment env;
    init_environment(&env);

    // Compiling and running the program
    Bytecode bytecode;
    compile(argv[1], &bytecode);
    execute_bytecode(&bytecode, &env);

    return 0;
}
