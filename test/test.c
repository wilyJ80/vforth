#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lexer_test.h"
#include "datastack_test.h"

int main(void)
{
  lexerTest();
  printf("--- Lexer test passed\n");

  dataStackTest();
  printf("--- Data Stack test passed\n");


  return EXIT_SUCCESS;
}
