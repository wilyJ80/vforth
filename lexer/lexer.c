#include "lexer.h"
#include "char_match.h"
#include "types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 5
#define MAX_TRANSITIONS 4

void error(char *lexeme, int *lineCount) {
  printf("Error: malformed token at line %d: %s\n", *lineCount, lexeme);
}

struct Token getNextToken(FILE *fp, int *lineCount) {

  struct Transition transitionTable[MAX_STATES + 1][MAX_TRANSITIONS + 1] = {
      // Token category, char match callback, next state

      // State 0
      {{0, IGNORE, isIsSpace},
       {1, KEEP_BUILDING, isPrintNotSpaceNotDigitNotParenOpen},
       {3, KEEP_BUILDING, isIsDigit},
       {5, KEEP_BUILDING, isParenOpen}},
      // State 1
      {{1, KEEP_BUILDING, isPrintNotSpace}, {2, WORD, isNotPrintOrIsSpace}},
      // State 2: accepting
      {},
      // State 3
      {{1, KEEP_BUILDING, isPrintNotSpaceNotDigit},
       {3, KEEP_BUILDING, isIsDigit},
       {4, INT, isNotPrintOrIsSpace}},
      // State 4: accepting
      {},
      // State 5
      {{5, KEEP_BUILDING, isPrintOrNewlineOrTab}, {0, IGNORE, isParenClose}}};

  // running values
  char lexeme[MAX_SIZE_LEXEME] = "";
  int lexemeSize = 0;
  int state = 0;
  struct Token token;

  // Character consuming loop
  while (true) {
    char ch = fgetc(fp);

    // Return EOF token to signal the end: caller needs to check for EOF
    // themselves.
    if (ch == EOF) {
      token.category = END_OF_FILE;
      return token;
    }

    // Line skipping (for error reporting)
    if (ch == '\n') {
      (*lineCount)++;
    }

    bool foundTransition = false;

    // Loop through possible transitions looking for a match
    for (int possibleTransition = 0;
         possibleTransition < MAX_TRANSITIONS + 1 &&
         transitionTable[state][possibleTransition].charMatch != NULL;
         possibleTransition++) {

      if (transitionTable[state][possibleTransition].charMatch(ch)) {
        foundTransition = true;
        token.category = transitionTable[state][possibleTransition].category;

        // handle deconsuming of char that leads to accepting state, should not
        // unget newline to avoid overcounting the line counter
        if (token.category == WORD || token.category == INT) {
          ungetc(ch, fp);
        }

        switch (token.category) {

        case KEEP_BUILDING:
          lexeme[lexemeSize] = ch;
          lexeme[++lexemeSize] = '\0';
          break;

        case IGNORE:
          lexeme[0] = '\0';
          lexemeSize = 0;
          break;

        case INT:
          token.intValue = atoi(lexeme);
          return token;

        case WORD:
          strcpy(token.lexeme, lexeme);
          return token;

          default:
          break;
        }

        state = transitionTable[state][possibleTransition].nextState;
      }
    }

    if (!foundTransition) {
      lexeme[lexemeSize] = ch;
      lexeme[++lexemeSize] = '\0';
      token.category = MALFORMED;
      strcpy(token.lexeme, lexeme);
      return token;
    }
  }
}
