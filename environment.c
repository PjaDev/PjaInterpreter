#include <stdlib.h>
#include <string.h>
#include "environment.h"

void init_environment(Environment *env) {
    env->variables = NULL;
    env->variable_count = 0;
}

void add_variable(Environment *env, const char *name, int value) {
    env->variables = realloc(env->variables, sizeof(Variable) * (env->variable_count + 1));
    env->variables[env->variable_count].name = strdup(name);
    env->variables[env->variable_count].value = value;
    env->variable_count++;
}

int get_variable(Environment *env, const char *name) {
    for (int i = 0; i < env->variable_count; i++) {
        if (strcmp(env->variables[i].name, name) == 0) {
            return env->variables[i].value;
        }
    }
    return 0;
}

void free_environment(Environment *env) {
    for (int i = 0; i < env->variable_count; i++) {
        free(env->variables[i].name);
    }
    free(env->variables);
}
