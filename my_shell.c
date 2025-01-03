#include "main.h"

#define MAX_ARGS 128

/**
 * main_shell - entry of the shell
 * 
 * Return: 0 or error
 */

int main()
{
	char *comando = NULL;
	size_t largo = 0;
	char *args[MAX_ARGS];
	char *token;
	int contador = 0;

	printf("Bienvenido a la Shcaloneta\n");

	while(1)
	{
		printf("La Shcaloneta: ");
		fflush(stdout);

		if(getline(&comando, &largo, stdin) == -1)
		{
			perror("Error al leer la entrada");
			break;
		}

		comando[strcspn(comando, "\n")] = '\0';

		if (strcmp(comando, "exit") == 0)
		{
			printf("Se va La Shcaloneta...\n");
			break;
		}

		if (comando[0] == '\0')
			continue;
		contador = 0;
		token = strtok(comando, " ");
		while (token != NULL && contador < MAX_ARGS - 1)
		{
			args[contador++] = token;
			token = strtok(NULL, " ");
		}
		args[contador] = NULL;
		printf("Comando: %s\n", args[0]);
	}
	free(comando);
	return (0);
}
