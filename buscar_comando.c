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
	char **paths;
	size_t i = 0;

	paths = dividir_path(path);

	while (paths[i])
	{
		char *ruta_completa = construir_ruta_completa(paths[i], comando);

		if (!ruta_completa)
		{
			liberar_memoria_paths(paths, i);
			return (NULL);
		}

		if (verificar_comando(ruta_completa))
		{
			liberar_memoria_paths(paths, i);
			return (ruta_completa);
		}

		free(ruta_completa);
		i++;
	}

	liberar_memoria_paths(paths, i);
	return (NULL);
}
