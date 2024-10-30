#include <stdio.h>
#include "error.h"

void print_error(ErrorType error_type, const char *message) {
    switch (error_type) {
        case SYNTAX_ERROR:
            fprintf(stderr, "Syntax Error: %s\n", message);
            break;
        case RUNTIME_ERROR:
            fprintf(stderr, "Runtime Error: %s\n", message);
            break;
        case TYPE_ERROR:
            fprintf(stderr, "Type Error: %s\n", message);
            break;
    }
}
