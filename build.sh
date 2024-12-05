#!/bin/bash

if [[ $1 == 'test' ]]; then
		gcc -g ./interpreter/*.c ./test/*.c ./lexer/*.c -o dist/vforth
		echo 'built test.'
else
		gcc -g main.c ./lexer/*.c -o dist/vforth
		echo 'built main.'
fi
