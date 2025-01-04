#include "main.h"

/**
 * dividir_comando - dividir comando
 * @line: linea de comando
 * Return: token definido
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
		comando = strtok(NULL, " \n");
		pos++;
	}
	token[pos] = NULL;
	return (token);
}
