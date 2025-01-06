#include "main.h"

/**
 * dividir_path - divides the PATH string into individual directories
 * @path: the PATH environment variable
 * Return: array of directories (strings)
 */
char **dividir_path(char *path)
{
	return (dividir_comando(strdup(path)));
}

/**
 * buscar_comando - searches for the command in the directories listed in PATH
 * @comando: the command to search for
 * Return: complete path to the command if found, NULL otherwise
 */

char *buscar_comando(char *comando)
{
	char *path = getenv("PATH");
	char *copia_ruta, *ruta_completa, *paths;
	size_t len_comando, len_direccion;

	if (!path || !comando)
		return (NULL);

	copia_ruta = strdup(path);

	if (!copia_ruta)
		return (NULL);

	len_comando = strlen(comando);

	paths = strtok(copia_ruta, ":");

	while (paths)
	{
		len_direccion = strlen(paths);
		ruta_completa = malloc(len_direccion + len_comando + 2);
		if (!ruta_completa)
		{
			free(copia_ruta);
			return (NULL);
		}

		sprintf(ruta_completa, "%s/%s", paths, comando);

		if (verificar_comando(ruta_completa))
		{
			free(copia_ruta);
			return (ruta_completa);
		}

		free(ruta_completa);
		paths = strtok(NULL, ":");
	}

	free(copia_ruta);
	return (NULL);
}
