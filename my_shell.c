#include "main.h"

int main()
{
	char *comando = NULL;
	size_t largo = 0;
	int args = 0;
	char *token = strtok(comando, " ");

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

		if (strcmp(comando, "exit") == 0)
		{
			printf("Se va La Shcaloneta...\n");
			break;
		}
	}
	while (token != NULL)
	{
		token = strtok(NULL, " ");
	}
	free(comando);
	return (0);
}
