#ifndef AST_H
#define AST_H

typedef enum {
    NODE_CONST,
    NODE_VAR,
    NODE_ASSIGN,
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV
} NodeType;

typedef struct Node {
    NodeType type;
    union {
        int int_value;
        char *var_name;
        struct {
            struct Node *left;
            struct Node *right;
        };
    };
} Node;

Node *new_node_const(int value);
Node *new_node_var(char *name);
Node *new_node_assign(Node *var, Node *expr);
Node *new_node_op(NodeType type, Node *left, Node *right);
void free_node(Node *node);

#endif
