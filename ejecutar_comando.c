#include "main.h"

/**
 * ejecutar_comando - executes a command in a child process
 * @args: array of argument string
 */

void ejecutar_comando(char **args)
{
	pid_t pid;
	int estado;
	char *comando_completo;

	comando_completo = buscar_comando(args[0]);

	if (!comando_completo)
	{
		fprintf(stderr, "Comando no encontrado: %s\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(comando_completo, args, NULL) == -1)
		{
			perror("Error al ejecutar comando");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("Error al crear proceso");
	else
		waitpid(pid, &estado, 0);

	free(comando_completo);
}
