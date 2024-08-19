#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

enum TokenType {
	// Single-character tokens.
	COLON, SEMICOLON,
	MINUS, PLUS, SLASH, STAR,

	// One or two character tokens.
	EQUAL, NOT_EQUAL,
	LESS, GREATER,
	U_LESS, U_GREATER,
	IS_ZERO, IS_NEGATIVE, IS_POSITIVE,

	// Literals.
	WORD, NUMBER,

	// Keywords.
	AND, OR,
	IF, ELSE, THEN,
	// DO, LOOP, BEGIN, WHILE, REPEAT,
	
};

#endif // !TOKEN_TYPE_H
