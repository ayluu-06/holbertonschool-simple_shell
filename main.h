#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int print_env(char **env);
char **dividir_comando(char *line);
void ejecutar_comando(char **args, char **env);

#endif
