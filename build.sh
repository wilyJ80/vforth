#!/bin/bash

if [[ $1 == 'main' ]]; then
		gcc -g main.c lexer.c eval.c -o vforth
		echo 'built main.'
elif [[ $1 == 'test' ]]; then
		gcc -g ./lexer.c ./test/test.c -o vforth
		echo 'built test.'
else
		gcc -g debug.c lexer.c eval.c -o vforth
		echo 'built debug.'
fi
