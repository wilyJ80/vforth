#include "lexer.h"
#include "eval.h"
#include "types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /*if (argc != 2) {*/
  /*  fprintf(stderr, "Error. Usage: vforth <file>\n");*/
  /*  return EXIT_FAILURE;*/
  /*}*/
  const char *filename = "example.fth";

  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening source file.\n");
    return EXIT_FAILURE;
  }

  int lineCount = 1;
  struct DataStack dataStack;
  initDataStack(&dataStack);

  while (true) {
    struct Token token = getNextChar(fp, &lineCount);
    if (token.category == END_OF_FILE) {
      printf("EOF Found\n");
      break;
    } else {
      printToken(token);
      evalToken(token, &dataStack);
    }
  }

  printDataStack(&dataStack);

  return EXIT_SUCCESS;
}

