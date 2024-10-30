%{
#include "parser.h"
%}

digit  [0-9]
letter [a-zA-Z]

%%

"public"         return PUBLIC;
"class"          return CLASS;
"static"         return STATIC;
"void"           return VOID;
"int"            return INT;
"string"         return STRING;
"new"            return NEW;
{letter}+        return IDENTIFIER;
{digit}+         return NUMBER;
"{"              return LBRACE;
"}"              return RBRACE;
"("              return LPAREN;
")"              return RPAREN;
";"              return SEMICOLON;
"="              return ASSIGN;
"+"              return PLUS;
"-"              return MINUS;
"*"              return TIMES;
"/"              return DIVIDE;
[ \t\n]+         /* ignore whitespace */;
.                return yytext[0];

%%
