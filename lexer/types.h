#ifndef TYPES_H
#define TYPES_H

#define MAX_SIZE_LEXEME 31
#define MAX_STACK_SIZE 11

enum TOKEN_CATEGORY { WORD, INT, NEWLINE, COMMENT, END_OF_FILE };

struct Token {
  enum TOKEN_CATEGORY category;
  union {
    int intValue;
    char lexeme[MAX_SIZE_LEXEME];
  };
};

struct DataStack {
  int top;
  int value[MAX_STACK_SIZE];
};

// ReturnStack

#endif // !TYPES_H
