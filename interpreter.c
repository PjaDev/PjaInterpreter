#include "interpreter.h"

int interpret(Node *node, Environment *env) {
    switch (node->type) {
        case NODE_CONST:
            return node->int_value;
        case NODE_VAR:
            return get_variable(env, node->var_name);
        case NODE_ASSIGN:
            add_variable(env, node->left->var_name, interpret(node->right, env));
            return 0;
        case NODE_ADD:
            return interpret(node->left, env) + interpret(node->right, env);
        case NODE_SUB:
            return interpret(node->left, env) - interpret(node->right, env);
        case NODE_MUL:
            return interpret(node->left, env) * interpret(node->right, env);
        case NODE_DIV:
            return interpret(node->left, env) / interpret(node->right, env);
    }
    return 0;
}
