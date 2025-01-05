#include "main.h"

/**
 * dividir_path - divides the PATH string into individual directories
 * @path: the PATH environment variable
 * Return: array of directories (strings)
 */
char **dividir_path(char *path)
{
	return (dividir_comando(path));
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

	if (!path)
		return (NULL);

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
