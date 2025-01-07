#include "main.h"

/**
 * print_env - prints the current environment variables
 * @env: an array of environment variables
 * Return: 0 on success, 1 if the env array is NULL
 */

int print_env(char **env)
{
	unsigned int i = 0;

	if (env == NULL)
		return (1);

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
