#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdbool.h>

void error(char *lexeme, int *lineCount);

bool isPrintNotSpaceNotDigit(char ch);
bool isPrintNotSpace(char ch);

struct Token getNextToken(FILE *fp, int *lineCount);

void printToken(struct Token token);

#endif // !LEXER_H
