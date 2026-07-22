*This project has been created as part of the 42 curriculum by tgeler, fatmdemi.*

# Minishell

## Description
Minishell is a small interactive shell written in C as part of the 42 curriculum. The goal of the project is to reproduce the core behavior of a Unix shell while learning how command parsing, process creation, redirections, environment variables, and signals work together.

The codebase follows a classic shell pipeline: the lexer turns the input line into tokens, the parser builds the command structure, and the executor runs commands while handling expansions and redirections at execution time.

## Instructions

### Requirements
- A C compiler such as `cc`, `gcc`, or `clang`
- `make`
- The `readline` library

### Compilation
Build the project with:

```bash
make
```

Clean build artifacts with:

```bash
make clean
make fclean
make re
```

### Execution
Run the shell in interactive mode with:

```bash
./minishell
```

You can also pipe commands into it:

```bash
echo "pwd" | ./minishell
```

## Features
The current implementation includes:

- Prompt-based interactive shell using `readline`
- Tokenization and syntax parsing
- Pipes (`|`)
- Input, output, append, and heredoc redirections (`<`, `>`, `>>`, `<<`)
- Variable expansion such as `$VAR` and `$?`
- Signal handling for interactive shell behavior
- Built-ins:
	- `echo`
	- `cd`
	- `pwd`
	- `export`
	- `unset`
	- `env`
	- `exit`

## Resources
Useful references for this project:

- GNU Bash Manual
- `man` pages for `fork`, `execve`, `pipe`, `dup`, `dup2`, `wait`, `waitpid`, `signal`, `sigaction`, and `readline`
- The `readline` documentation
- 42 project documentation and peer evaluations

### AI Usage
AI tools were used as support during the project for architecture discussions, debugging shell edge cases, improving README structure, and checking text clarity. The implementation decisions, final behavior, and code changes were made by the team.

## Authors
- tgeler: shell execution flow, built-ins, environment management, redirections, and overall integration
- fatmdemi: lexer, parser, token handling, syntax analysis, and command structure parsing