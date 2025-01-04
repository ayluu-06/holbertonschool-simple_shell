#include "main.h"

void ejecutar_comando(char **args, char **env)
{
	pid_t pid;
	int estado;

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear proceso");
		return;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Error al ejecutar el comando");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do
			waitpid(pid, &estado, WUNTRACED);
		while (!WIFEXITED(estado) && !WIFSIGNALED(estado));
	}
}
