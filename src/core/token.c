#include "token.h"
#include <stdlib.h>
#include <stdio.h>

struct Token create_token(enum TokenType type, const char *lexeme, union Literal literal, int line) {
	struct Token token;
	token.type = type;
	token.lexeme = lexeme;
	token.literal = literal;
	token.line = line;

	return token;
}

const char* to_string(struct Token token) {
	/*********************
		* BRUH... *
		* I'm not being paid for this shit*
		*  😭
		* *
	*/

	// Allocate memory for the string representation (adjust size as needed)
    char* result = malloc(256);

    // Convert the literal value to a string based on its type
    if (token.type == INTEGER) { // Assume TOKEN_NUMBER is for integers
        snprintf(result, 256, "%d", token.literal.int_value);
    } else if (token.type == DOUBLE) { // Assume TOKEN_DOUBLE is for floating-point numbers
        snprintf(result, 256, "%f", token.literal.double_value);
    } else if (token.type == STRING) { // Assume TOKEN_STRING is for strings
        snprintf(result, 256, "%s", token.literal.string_value);
    } else {
        snprintf(result, 256, "null");
    }

    // Format the final string (type, lexeme, literal)
    char* final_result = malloc(512); // Adjust size as needed
    snprintf(final_result, 512, "%d %s %s", token.type, token.lexeme, result);

    free(result); // Free the temporary result string
    return final_result; // Caller must free this string
}
