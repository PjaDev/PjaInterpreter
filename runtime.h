#ifndef RUNTIME_H
#define RUNTIME_H

#include "compiler.h"
#include "environment.h"

// Fungsi untuk menjalankan bytecode
void execute_bytecode(Bytecode *bytecode, Environment *env);

#endif
