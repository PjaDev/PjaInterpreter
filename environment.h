#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

typedef struct {
    char *name;
    int value;
} Variable;

typedef struct {
    Variable *variables;
    int variable_count;
} Environment;

void init_environment(Environment *env);
void add_variable(Environment *env, const char *name, int value);
int get_variable(Environment *env, const char *name);
void free_environment(Environment *env);

#endif
