#include "main.h"

int my_shell()
{
	char *comando = NULL;
	size_t largo = 0;

	while(1)
	{
		printf("la_shcaloneta: ");
		getline(&comando, &largo, stdin);

		comando[strcspn(comando, "\n")] = 0;

		if (strcmp(comando, "exit") == 0)
		{
			printf("Se va la shcaloneta...\n");
			break;
		}
	}
	free(comando);
	return (0);
}
