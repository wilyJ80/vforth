#include "lexer_test.h"
#include "../lexer/lexer.h"
#include "../lexer/types.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void lexerTest() {
  const char *mock_data = "2 + *\n";
  FILE *mock_file = fmemopen((void *)mock_data, strlen(mock_data), "r");

  if (mock_file == NULL) {
    fprintf(stderr, "Error opening source file.\n");
    exit(EXIT_FAILURE);
  }

  int lineCount = 1;
  struct Token tokens[4];
  int index = 0;

  while (true) {
    struct Token token = getNextToken(mock_file, &lineCount);
    if (token.category == END_OF_FILE) {
      break;
    }
    tokens[index] = token;
    index++;
  }

  assert(tokens[0].category == INT);
  assert(tokens[0].intValue == 2);
  
  assert(tokens[1].category == WORD);
  assert(strcmp(tokens[1].lexeme, "+") == 0);

  assert(tokens[2].category == WORD);
  assert(strcmp(tokens[2].lexeme, "*") == 0);
}
