#include "main.h"

/**
 * ejecutar_comando - executes a command in a child process
 * @args: array of argument string
 */

void ejecutar_comando(char **args, char **envp)
{
	pid_t pid;
	int estado;
	char *comando_completo;

	comando_completo = buscar_comando(args[0]);

	if (!comando_completo)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(comando_completo, args, envp) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("Error al crear proceso");
	else
	{
		waitpid(pid, &estado, 0);
		if (WIFEXITED(estado))
		{
			int exit_status = WEXITSTATUS(estado);
			if (exit_status != 0)
				fprintf(stderr, "Comando %s terminó con código de salida %d\n", args[0], exit_status);
		
		}
		else
			fprintf(stderr, "El comando %s no terminó correctamente\n", args[0]);
	}

	free(comando_completo);
}

