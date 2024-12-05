#include "datastack_test.h"
#include "../interpreter/stack.h"
#include "../lexer/lexer.h"
#include "../lexer/types.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dataStackTest() {
  const char *mock_data = "2 3 77 +\n";
  FILE *mock_file = fmemopen((void *)mock_data, strlen(mock_data), "r");

  if (mock_file == NULL) {
    fprintf(stderr, "Error opening source file.\n");
    exit(EXIT_FAILURE);
  }

  int lineCount = 1;
  struct Token tokens[4];
  int index = 0;

  struct DataStack dataStack = createDataStack();

  while (true) {
    struct Token token = getNextToken(mock_file, &lineCount);
    if (token.category == END_OF_FILE) {
      break;
    }
    loadToken(&dataStack, token);
  }

  int top = dataStack.top;
  assert(dataStack.value[top] == 77);
  assert(dataStack.value[top-1] == 3);
  assert(dataStack.value[top-2] == 2);
}
