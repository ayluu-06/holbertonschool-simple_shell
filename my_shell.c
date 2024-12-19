#include "main.h"

int my_shell()
{
	char comando[256];

	while(1)
	{
		printf("la_shcaloneta: ");
		fgets(comando, sizeof(comando), stdin);

		if (strcmp(comando, "exit") == 0)
		{
			printf("Se va la shcaloneta...\n");
			break;
		}
	}
	return (0);
}
