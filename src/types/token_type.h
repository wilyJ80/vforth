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
	WORD, STRING, INTEGER, DOUBLE,

	// Keywords.
	AND, OR,
	IF, ELSE, THEN,
	// Did not study Forth loops yet lol, (to be implemented)
	// DO, LOOP, BEGIN, WHILE, REPEAT,
	
	EOF
};

#endif // !TOKEN_TYPE_H
