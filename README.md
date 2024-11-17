# Running

## Main

`./build.sh`

- Will be built inside /dist

- Run with `./vforth <file>`

## Test

`./build.sh test`

- Run with `./vforth`

# Todo

- [X] Cleanup lexer

Eval:

- [X] PROBLEM: INFINITE LOOP
- [ ] Stacks data tokens correctly
- [ ] Stack function, stack information consumption function
    - [ ] print stack word: .S
    - [ ] pop top word: .
- [ ] Stacks basic words and operates on data: math basic operations and swap, dup, drop, rot, over
- [ ] Stacks words: reserved words call functions. Create string data type?
