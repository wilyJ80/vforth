#include <stdbool.h>
#include <ctype.h>

bool isPrintNotSpaceNotDigit(char ch) {
  return isprint(ch) && ch != ' ' && !isdigit(ch);
}

bool isPrintNotSpaceNotDigitNotParenOpen(char ch) {
  return isprint(ch) && ch != ' ' && !isdigit(ch) && ch != '(';
}

bool isPrintNotSpace(char ch) { return isprint(ch) && ch != ' '; }

bool isNotPrintOrIsSpace(char ch) { return !isPrintNotSpace(ch); }

bool isIsSpace(char ch) { return isspace(ch) != 0; }

bool isIsDigit(char ch) { return isdigit(ch); }

bool isParenOpen(char ch) { return ch == '('; }

bool isParenClose(char ch) { return ch == ')'; }

bool isPrintOrNewlineOrTab(char ch) { return isprint(ch);}
