#include "main.h"

/**
 * dividir_comando - divides a command line into tokens
 * @line: command line input
 * Return: array of tokens (strings)
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

	comando = strtok(line, "  \n");
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

		comando = strtok(NULL, " \n");
	}
	token[pos] = NULL;
	return (token);
}
