#ifndef LEXER_TYPES_H
#define LEXER_TYPES_H

#define MAX_SIZE_LEXEME 31

enum TOKEN_CATEGORY { WORD, INT, KEEP_BUILDING, NEWLINE, IGNORE, END_OF_FILE, MALFORMED };

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
  bool (*charMatch)(char);
};

#endif // !LEXER_TYPES_H
