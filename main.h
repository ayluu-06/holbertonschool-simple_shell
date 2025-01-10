#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "env_utils.h"

void exit_shell(char **args, char *line);
int read_entry(char **line, size_t *largo);
int prcs_command(char **args, char *line, char **envp);
int main(int argc, char **envp);
char **dividir_path(char *path);
char *construir_ruta_completa(char *ruta, char *comando);
int verificar_comando(char *ruta_completa);
void liberar_memoria_paths(char **paths, size_t i);
char *buscar_comando(char *comando);
int print_env(char **env);
void ejecutar_comando(char **args, char **envp);
char **dividir_comando(char *line);

#endif
