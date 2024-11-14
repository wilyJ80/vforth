#ifndef EVAL_H
#define EVAL_H

#include "../lexer/types.h"

void initDataStack(struct DataStack *dataStack);
void pushDataStack(struct DataStack *dataStack, int value);
void popDataStack(struct DataStack *dataStack);
void printDataStack(struct DataStack *dataStack);

void evalToken(struct Token token, struct DataStack *dataStack);

#endif // !EVAL_H
