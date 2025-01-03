#include "main.h"

/**
 * main_shell - entry of the shell
 * 
 * Return: 0 or error
 */

int main()
{
	char *line = NULL;
	size_t largo = 0;
	char **args;
	int contador = 0;

	printf("Bienvenido a la Shcaloneta\n");

	while(1)
	{
		printf("La Shcaloneta: ");
		fflush(stdout);

		if(getline(&line, &largo, stdin) == -1)
		{
			perror("Error al leer la entrada");
			break;
		}
		
		args = dividir_comando(line);

		if (strcmp(line, "exit") == 0)
		{
			printf("Se va La Shcaloneta...\n");
			break;
		}

		if (!args || !args[0])
		{
			free(args);
			continue;
		}

		args[contador] = NULL;
		free(args);
	}
	free(line);
	return (0);
}
