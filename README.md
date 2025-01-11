# Simple Shell

## Description
This project is a custom implementation of a UNIX command-line interpreter, also known as a shell. It replicates the functionality of the sh shell, handling both interactive and non-interactive modes. The shell supports basic commands, environment variables, and error handling.

## Features
- Execute commands from the PATH.
- Handle built-in commands like exit and env.
- Interactive and non-interactive modes.
- Error messages that mimic the format of /bin/sh.

## Installation
To compile the shell, run:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage
### Interactive Mode
Run the shell and enter commands interactively:
```bash
./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
```

### Non-Interactive Mode
The shell also processes commands passed via a pipe or a file:
```bash
echo "/bin/ls" | ./hsh
hsh main.c shell.c

cat commands.txt | ./hsh
hsh main.c shell.c test_ls_2
```

## File Structure
- **main.h**: Header file containing function prototypes and includes.
- **env_utils.c**: Handles environment variable functions, such as fetching and parsing PATH.
- **main.c**: Entry point of the program. Manages the shell loop and processes user input.
- **execute.c**: Contains the function to execute commands via fork and execve.
- **path_utils.c**: Handles PATH parsing, building full command paths, and validating commands.
- **command_utils.c**: Tokenizes user input into commands and arguments.
- **memory_utils.c**: Manages memory allocation and deallocation for dynamic arrays.

## Functions Used
This project uses only the following system calls and standard library functions:
- access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, printf, fprintf, vfprintf, sprintf, putchar, read, readdir, signal, stat, lstat, fstat, strtok, wait, waitpid, wait3, wait4, and write.
## Known Issues
- The shell does not support advanced features like piping (|) or file redirection (>).
- Built-in commands are limited to exit and env.

## Authors
- [Aylin Pintos](https://github.com/ayluu-06)
- [Federico Angeriz] (https://github.com/FedeAngeriz)
