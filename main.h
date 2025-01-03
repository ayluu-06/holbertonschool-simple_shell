#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int print_env(char **env);
int run_execve(void);
int fork(void);
int main(void);
int getpid(void);
int stat(int ac, char **av);
int wait(void);
char **dividir_comando(char *line);

#endif
