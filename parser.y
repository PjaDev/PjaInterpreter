%{
#include "ast.h"
extern int yylex();
void yyerror(const char *s);
%}

%token PUBLIC CLASS STATIC VOID INT STRING NEW IDENTIFIER NUMBER
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON ASSIGN
%left PLUS MINUS
%left TIMES DIVIDE

%%

program:
    class_definition
    ;

class_definition:
    PUBLIC CLASS IDENTIFIER LBRACE class_body RBRACE
    ;

class_body:
    PUBLIC STATIC VOID IDENTIFIER LPAREN RPAREN LBRACE statement RBRACE
    ;

statement:
    expression SEMICOLON
    ;

expression:
    IDENTIFIER ASSIGN expression
    | NUMBER
    | IDENTIFIER
    | expression PLUS expression
    | expression MINUS expression
    | expression TIMES expression
    | expression DIVIDE expression
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
