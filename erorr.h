#ifndef ERROR_H
#define ERROR_H

// Daftar tipe error
typedef enum {
    SYNTAX_ERROR,
    RUNTIME_ERROR,
    TYPE_ERROR
} ErrorType;

// Fungsi untuk mencetak pesan error
void print_error(ErrorType error_type, const char *message);

#endif
