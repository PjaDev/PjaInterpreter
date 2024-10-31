#ifndef PARSER_H
#define PARSER_H

#include "ast.h"

// Token enumeration for lexer/parser
typedef enum {
    TOKEN_EOF,            // End of file
    TOKEN_IDENTIFIER,      // Identifier (variable/function name, etc.)
    TOKEN_NUMBER,          // Integer numbers
    TOKEN_STRING_LITERAL,  // String literals
    TOKEN_INCLUDE,         // "include"
    TOKEN_REQUIRE,         // "require"
    TOKEN_NAMESPACE,       // "namespace"
    TOKEN_USE,             // "use"
    TOKEN_PUBLIC,          // "public"
    TOKEN_CLASS,           // "class"
    TOKEN_STATIC,          // "static"
    TOKEN_VOID,            // "void"
    TOKEN_INT,             // "int"
    TOKEN_STRING,          // "string"
    TOKEN_IF,              // "if"
    TOKEN_ELSE,            // "else"
    TOKEN_WHILE,           // "while"
    TOKEN_RETURN,          // "return"
    TOKEN_PLUS,            // "+"
    TOKEN_MINUS,           // "-"
    TOKEN_STAR,            // "*"
    TOKEN_SLASH,           // "/"
    TOKEN_ASSIGN,          // "="
    TOKEN_LPAREN,          // "("
    TOKEN_RPAREN,          // ")"
    TOKEN_LBRACE,          // "{"
    TOKEN_RBRACE,          // "}"
    TOKEN_SEMICOLON        // ";"
} TokenType;

// Lexer function prototypes
int yylex(void); // Lexer function that returns the next token
extern char *yytext; // The text of the current token

// Parsing function prototypes
int yyparse(void);  // Main parsing function
void yyerror(const char *msg); // Error handler function

// Include the AST (Abstract Syntax Tree) node structure definitions
Node *parse_program(void);  // Function to parse the whole program

#endif /* PARSER_H */
