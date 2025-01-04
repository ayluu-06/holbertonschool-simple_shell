#include "main.h"

/**
 * main - entry of the shell
 * 
 * Return: 0 or error
 */

int main(int argc, char **envp)
{
	char *line = NULL;
	size_t largo = 0;
	char **args;

	(void)argc;

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

		if (!args || !args[0])
		{
			free(args);
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
		{
			printf("Se va La Shcaloneta...\n");
			free(args);
			break;
		}
		else if (strcmp(args[0], "env") == 0)
			print_env(envp);
		else
			ejecutar_comando(args, envp);
		
		free(args);
	}

	free(line);
	return (0);
}
