#include "./lexer/lexer.h"
#include "./lexer/types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Error. Usage: vforth <file>\n");
    return EXIT_FAILURE;
  }
  const char *filename = argv[1];

  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening source file.\n");
    return EXIT_FAILURE;
  }

  int lineCount = 1;

  while (true) {
    struct Token token = getNextToken(fp, &lineCount);
    if (token.category == END_OF_FILE) {
      fclose(fp);
      exit(EXIT_SUCCESS);
    }

    switch (token.category) {
    case WORD:
      printf("<WORD, %s>\n", token.lexeme);
      break;

    case INT:
      printf("<INT, %d>\n", token.intValue);
      break;
    }
  }

  return EXIT_SUCCESS;
}
