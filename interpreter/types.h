#ifndef INTERPRETER_TYPES_H
#define INTERPRETER_TYPES_H

#define MAX_STACK_SIZE 11

struct DataStack {
  int top;
  int value[MAX_STACK_SIZE];
};

// ReturnStack

#endif // !INTERPRETER_TYPES_H
