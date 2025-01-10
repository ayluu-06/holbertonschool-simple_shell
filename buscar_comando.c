#include "main.h"

/**
 * dividir_path - divides the PATH string into individual directories
 * @path: the PATH environment variable
 * Return: array of directories (strings)
 */
char **dividir_path(char *path)
{
	char *path_copy;

	path_copy = malloc(strlen(path) + 1);
	if (!path_copy)
	{
		perror("Error al asignar memoria");
		return (NULL);
	}
	strcpy(path_copy, path);

	return (dividir_comando(path_copy));
}

/**
 * check_and_return - constructs the full path and checks if it is executable
 * @paths: the directory path to check
 * @comando: the command to append to the directory path
 * Return: the full path if the command is executable, NULL otherwise
 */

char *check_and_return(char *paths, char *comando)
{
	size_t len_direccion = strlen(paths);
	size_t len_comando = strlen(comando);
	char *ruta_completa = malloc(len_direccion + len_comando + 2);

	if (!ruta_completa)
		return (NULL);

	sprintf(ruta_completa, "%s/%s", paths, comando);

	if (verificar_comando(ruta_completa))
		return (ruta_completa);

	free(ruta_completa);
	return (NULL);
}

/**
 * buscar_comando - searches for command in the directories listed
 * @comando: the command to search for
 * Return: complete path to the command if found, NULL otherwise
 */

char *buscar_comando(char *comando)
{
	char *path = getenv("PATH");
	char *copia_ruta, *paths;
	char *ruta_completa;

	if (!path || !comando)
		return (NULL);

	if (comando[0] == '/')
	{
		if (verificar_comando(comando))
			return (strdup(comando));
		else
			return (NULL);
	}

	copia_ruta = strdup(path);
	if (!copia_ruta)
		return (NULL);

	paths = strtok(copia_ruta, ":");

	while (paths)
	{
		ruta_completa = check_and_return(paths, comando);
		if (ruta_completa)
		{
			free(copia_ruta);
			return (ruta_completa);
		}
		paths = strtok(NULL, ":");
	}

	free(copia_ruta);
	return (NULL);
}
