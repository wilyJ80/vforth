#include "scanner.h"

struct Scanner create_scanner(const char *source, const struct Token *tokens) {
	struct Scanner scanner;
	scanner.source = source;
	scanner.tokens = tokens;
	return scanner;
}
