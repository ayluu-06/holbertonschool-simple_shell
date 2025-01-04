#include "main.h"

/**
 * ejecutar_comando - executes a command in a child process
 * @args: array of argument string
 * @env: enviroment variables for the execve function
 */

void ejecutar_comando(char **args, char **env)
{
	pid_t pid;
	int estado;
	char *comando_completo;

	comando_completo = buscar_comando(args[0]);

	if(!comando_completo)
	{
		fprintf(stderr, "La Shcaloneta: Comando no encontrado: %s\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear proceso");
		free(comando_completo);
		return;
	}
	if (pid == 0)
	{
		if (execve(comando_completo, args, env) == -1)
		{
			perror("Error al ejecutar el comando");
			free(comando_completo);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do
			waitpid(pid, &estado, WUNTRACED);
		while (!WIFEXITED(estado) && !WIFSIGNALED(estado));
	}

	free(comando_completo);
}
