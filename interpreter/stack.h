#ifndef INTERPRETER_TYPES_H
#define INTERPRETER_TYPES_H

#define MAX_STACK_SIZE 777

#include "../lexer/types.h"

struct DataStack {
  int top;
  int value[MAX_STACK_SIZE];
};

struct ReturnStack {
  int top;
  // should operate on how many words?
  union {
  void (*operateOnAWord)(int);
  void (*operateOnTwoWords)(int, int);
  };
};

struct DataStack createDataStack();
struct ReturnStack createReturnStack();
void loadToken(struct DataStack dataStack, struct ReturnStack returnStack, struct Token token);
void consumeStack(struct DataStack stack);

#endif // !INTERPRETER_TYPES_H
