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

- [ ] Stack function, stack information consumption function
- [ ] Stacks data tokens correctly
    - [ ] print stack word: .S
    - [ ] pop top word: .
- [ ] Stacks basic words and operates on data: math basic operations and swap, dup, drop, rot, over
- [ ] Stacks words: reserved words call functions. Create string data type?
