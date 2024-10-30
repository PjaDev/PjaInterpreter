#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast.h"
#include "environment.h"

int interpret(Node *node, Environment *env);

#endif
