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
 * read_entry - reads user input
 * @line: input line
 * @largo: size of the buffer
 * Return: 0 if ok, -1 in case of error or EOF
 */

int read_entry(char **line, size_t *largo)
{
	if (getline(line, largo, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\nFin de archivo (Ctrl+D) detectado. Saliendo...\n");
			return (-1);
		}
		perror("Error al leer la entrada");
		return (1);
	}
	return (0);
}

/**
 * prcs_command - processes the command entered by the user
 * @args: command arguments
 * @line: input line
 * @envp: enviroment variables
 * Return: 0 if processed, -1 if should exit
 */

int prcs_command(char **args, char *line, char **envp)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit_shell(args, line);
		return (-1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env(envp);
	}
	else
	{
		ejecutar_comando(args, envp);
	}

	return (0);
}

/**
 * main - entry point for the shell program
 * @argc: argument count
 * @envp: array of environment variables passed to the program
 * Return: 0 on success, or -1 on error
 */

int main(int argc, char **envp)
{
	char *line = NULL;
	size_t largo = 0;
	char **args;
	int i;

	(void)argc;

	while (1)
	{
		fflush(stdout);
		if (read_entry(&line, &largo) == -1)
			break;

		args = dividir_comando(line);

		if (!args || !args[0])
		{
			free(args);
			continue;
		}
		if (prcs_command(args, line, envp) == -1)
			break;

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}

	free(line);
	return (0);
}
