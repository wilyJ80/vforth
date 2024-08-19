#ifndef TOKEN_H
#define TOKEN_H

#include "../types/token_type.h"

union Literal {
	int int_value;
	double double_value;
	char* string_value;
};

struct Token {
	const TokenType type;
	const char* lexeme;
	Literal literal;
	const int line;
};

Token createToken(TokenType type, const char* lexeme, Literal literal, int line);

const char* to_string(Token token);

#endif // !TOKEN_H
