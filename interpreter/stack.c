#include "stack.h"
#include "../lexer/types.h"
#include <stdlib.h>

struct DataStack createDataStack() {
  struct DataStack stack;
  // stack starts empty
  stack.top = -1;
  return stack;
}

struct ReturnStack createReturnStack() {
  struct ReturnStack returnStack;
  // function pointer starts NULL
  return returnStack;
}

void loadToken(struct DataStack dataStack, struct ReturnStack returnStack,
               struct Token token) {}

void consumeStack(struct DataStack dataStack) {}
