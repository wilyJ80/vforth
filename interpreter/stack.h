#ifndef INTERPRETER_TYPES_H
#define INTERPRETER_TYPES_H

#define MAX_STACK_SIZE 777

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

// ReturnStack

#endif // !INTERPRETER_TYPES_H
