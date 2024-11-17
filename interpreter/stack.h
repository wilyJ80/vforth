#ifndef INTERPRETER_TYPES_H
#define INTERPRETER_TYPES_H

#define MAX_STACK_SIZE 255

#include "../lexer/types.h"

struct DataStack {
  int top;
  int value[MAX_STACK_SIZE];
};

struct ReturnStack {
  int top;
  void (*function[MAX_STACK_SIZE])(void);
};

struct DataStack createDataStack();
struct ReturnStack createReturnStack();

void pushInt(struct DataStack *dataStack, int n);
void pushFunction(struct ReturnStack *returnStack, struct Token token);

void loadToken(struct DataStack *dataStack, struct Token token);

void consumeStack(struct DataStack stack);

#endif // !INTERPRETER_TYPES_H
