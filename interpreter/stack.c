#include "stack.h"
#include "../lexer/types.h"
#include <stdio.h>
#include <stdlib.h>

struct DataStack createDataStack() {
  struct DataStack stack;
  // stack starts empty
  stack.top = -1;
  return stack;
}

void pushInt(struct DataStack *dataStack, int number) {
  // check for overflow
  if (dataStack->top == MAX_STACK_SIZE) {
    fprintf(stderr, "Data stack overflow\n");
    exit(EXIT_FAILURE);
  }
  // perform push
  dataStack->top++;
  dataStack->value[dataStack->top] = number;
}

void loadToken(struct DataStack *dataStack, struct Token token) {
  if (token.category == INT) {
    pushInt(dataStack, token.intValue);
  }
}

struct ReturnStack createReturnStack() {
  struct ReturnStack returnStack;
  // function pointer starts NULL
  return returnStack;
}

void consumeStack(struct DataStack dataStack) {}
