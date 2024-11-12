#ifndef TYPES_H
#define TYPES_H

#define MAX_SIZE_LEXEME 31

enum TOKEN_CATEGORY { WORD, INT, NEWLINE, END_OF_FILE };

struct Token {
  enum TOKEN_CATEGORY category;
  union {
    int intValue;
    char lexeme[MAX_SIZE_LEXEME];
  };
};

#endif // !TYPES_H
