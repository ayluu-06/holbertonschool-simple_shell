#include "main.h"

/**
 * exit_shell - handles cleaning and exiting the shell
 * @args: the arguments array to free
 * @line: the input line to free
 */

void exit_shell(char **args, char *line)
{
	printf("Se va la Shcaloneta...\n");
	free(args);
	free(line);
	exit(0);
}

/**
 * main - entry point for the shell program
 * @argc: argument count
 * @envp: enviroment variables passed to the program
 * Return: 0 or error
 */

int main(int argc, char **envp)
{
	char *line = NULL;
	size_t largo = 0;
	char **args;

	(void)argc;

	printf("Bienvenido a la Shcaloneta\n");

	while (1)
	{
		printf("La Shcaloneta: ");
		fflush(stdout);

		if (getline(&line, &largo, stdin) == -1)
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
			exit_shell(args, line);
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
