#include "eval.h"
#include "./types.h"
#include <stdio.h>
#include <stdlib.h>

void initDataStack(struct DataStack *dataStack) { dataStack->top = -1; }

void pushDataStack(struct DataStack *dataStack, int value) {
  int newTop = dataStack->top + 1;
  if (newTop > MAX_STACK_SIZE) {
    fprintf(stderr, "Stack Overflow\n");
    exit(EXIT_FAILURE);
  }

  dataStack->value[newTop] = value;
  printf("Value %d pushed\n", value);
  dataStack->top++;
}

void printDataStack(struct DataStack *dataStack) {
  printf("< ");
  for (int i = 0; i <= dataStack->top; i++) {
    printf("%d ", dataStack->value[i]);
  }
  printf(" >\n");
}

void evalToken(struct Token token, struct DataStack *dataStack) {
  if (token.category == INT) {
    pushDataStack(dataStack, token.intValue);
  }
}
