#include "main.h"

/**
 * dividir_comando - splits a command line into tokens
 * @line: the command line to split
 * Return: an array of tokens if successful, NULL otherwise
 */
char **dividir_comando(char *line)
{
	char **token = malloc(sizeof(char *) * 128);
	char *comando;
	size_t pos = 0;

	if (!token)
	{
		perror("Error al asignar memoria");
		return (NULL);
	}

	comando = strtok(line, " \t\n");
	while (comando != NULL)
	{
		token[pos] = strdup(comando);
		if (!token[pos])
		{
			perror("Error al duplicar comando");
			while (pos > 0)
			{
				free(token[--pos]);
			}
			free(token);
			return (NULL);
		}
		pos++;

		comando = strtok(NULL, " \t\n");
	}
	token[pos] = (NULL);
	return (token);
}

/**
 * construir_ruta_completa - constructs the full path for the command
 * @ruta: individual path directory
 * @comando: command to find
 * Return: complete path as a string
 */

char *construir_ruta_completa(char *ruta, char *comando)
{
	size_t ruta_len = strlen(ruta);
	size_t comando_len = strlen(comando);
	char *ruta_completa = malloc(strlen(ruta) + strlen(comando) + 2);

	if (!ruta_completa)
	{
		perror("Error al asignar memoria");
		return (NULL);
	}
	snprintf(ruta_completa, ruta_len + comando_len + 2, "%s/%s", ruta, comando);
	return (ruta_completa);
}

/**
 * verificar_comando - checks if the command exists and is executable
 * @ruta_completa: the complete path to the command
 * Return: 1 if executable, 0 if not
 */

int verificar_comando(char *ruta_completa)
{
	return (access(ruta_completa, X_OK) == 0);
}

/**
 * liberar_memoria_paths - frees the memory allocated for paths array
 * @paths: the array of paths to free
 * @i: the current index in paths array
 */

void liberar_memoria_paths(char **paths, size_t i)
{
	size_t j;

	for (j = 0; j < i; j++)
	{
		free(paths[j]);
	}
	free(paths);
}
