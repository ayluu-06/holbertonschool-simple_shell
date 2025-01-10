#ifndef ENV_UTILS_H
#define ENV_UTILS_H

extern char **environ;

char *get_env_var(const char *name);
char *buscar_comando(char *comando);

#endif
