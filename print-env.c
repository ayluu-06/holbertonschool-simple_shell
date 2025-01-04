#include "main.h"

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
