#ifndef SCANNER_H
#define SCANNER_H

#import "token.h"

struct Scanner {
	const char* source;
	const struct Token *tokens;
};

struct Scanner create_scanner(const char* source, const struct Token *tokens);

#endif // !SCANNER_H
