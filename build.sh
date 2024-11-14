#!/bin/bash

if [[ $1 == 'main' ]]; then
gcc -g main.c lexer.c eval.c -o vforth
echo 'built main.'
else
gcc -g debug.c lexer.c eval.c -o vforth
echo 'built debug.'
fi
