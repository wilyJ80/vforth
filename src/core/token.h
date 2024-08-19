#ifndef TOKEN_H
#define TOKEN_H

#include "../types/token_type.h"

union Literal {
	int int_value;
	double double_value;
	char* string_value;
};

struct Token {
	const enum TokenType type;
	const char* lexeme;
	union Literal literal;
	const int line;
};

struct Token create_token(enum TokenType type, const char* lexeme, union Literal literal, int line);

const char* to_string(struct Token token);

#endif // !TOKEN_H
