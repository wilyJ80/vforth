#!/bin/bash

if [[ $1 == 'test' ]]; then
		gcc -g ./test/test.c ./test/lexer_test.c ./lexer/lexer.c ./lexer/char_match.c -o dist/vforth
		echo 'built test.'
else
		gcc -g main.c ./lexer/*.c -o dist/vforth
		echo 'built main.'
fi
