#ifndef LEXER_TYPES_H
#define LEXER_TYPES_H

#define MAX_SIZE_LEXEME 31

#include <stdbool.h>

enum TOKEN_CATEGORY { WORD, INT, KEEP_BUILDING, IGNORE, END_OF_FILE, MALFORMED };

enum IS_ACCEPTING {
  ACCEPTING,
  NONACCEPTING
};

struct Token {
  enum TOKEN_CATEGORY category;
  union {
    int intValue;
    char lexeme[MAX_SIZE_LEXEME];
  };
};

struct Transition {
  int nextState;
  enum TOKEN_CATEGORY category;
  enum IS_ACCEPTING isAccepting;
  bool (*charMatch)(char);
};

#endif // !LEXER_TYPES_H
