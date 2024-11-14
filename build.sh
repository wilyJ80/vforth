#!/bin/bash

if [[ $1 == 'main' ]]; then
		gcc -g main.c lexer.c eval.c -o dist/vforth
		echo 'built main.'
elif [[ $1 == 'test' ]]; then
		gcc -g ./test/test.c ./test/lexer_test.c ./lexer.c -o dist/vforth
		echo 'built test.'
else
		gcc -g debug.c lexer.c eval.c -o dist/vforth
		echo 'built debug.'
fi
