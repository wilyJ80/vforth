#include "lexer.h"
#include "types.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char *lexeme, int *lineCount) {
  printf("Error: malformed token at line %d: %s\n", *lineCount, lexeme);
}

bool isPrintNotSpaceNotDigit(char ch) {
  return isprint(ch) && ch != ' ' && !isdigit(ch);
}

bool isPrintNotSpace(char ch) { return isprint(ch) && ch != ' '; }

struct Token getNextChar(FILE *fp, int *lineCount) {
  char lexeme[MAX_SIZE_LEXEME] = "";
  int lexemeSize = 0;
  int state = 0;
  struct Token token;

  while (true) {
    char ch = fgetc(fp);

    switch (state) {

    case 0:
      if (ch == ' ' || ch == '\t') {
        state = 0;

      } else if (ch == '\n') {
        state = 0;
        (*lineCount)++;
        return token;

      } else if (ch == EOF) {
        return token;

      } else if (isPrintNotSpaceNotDigit(ch)) {
        state = 1;
        lexeme[lexemeSize] = ch;
        lexeme[++lexemeSize] = '\0';

      } else if (isdigit(ch)) {
        state = 3;
        lexeme[lexemeSize] = ch;
        lexeme[++lexemeSize] = '\0';

      } else {
        error(lexeme, lineCount);
      }
      break;

    case 1:
      if (isPrintNotSpace(ch)) {
        state = 1;
        lexeme[lexemeSize] = ch;
        lexeme[++lexemeSize] = '\0';

      } else if (ch == ' ') {
        state = 2;
        ungetc(ch, fp);
        token.category = WORD;
        strcpy(token.lexeme, lexeme);
        return token;

      } else {
        error(lexeme, lineCount);
      }
      break;

    case 3:
      if (isdigit(ch)) {
        state = 3;
        lexeme[lexemeSize] = ch;
        lexeme[++lexemeSize] = '\0';

      } else if (isPrintNotSpaceNotDigit(ch)) {
        state = 1;
        lexeme[lexemeSize] = ch;
        lexeme[++lexemeSize] = '\0';

      } else if (ch == ' ') {
        state = 4;
        ungetc(ch, fp);
        token.category = INT;
        token.intValue = atoi(lexeme);
        return token;

      } else {
        error(lexeme, lineCount);
      }
      break;
    }
  }
}
