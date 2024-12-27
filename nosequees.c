#include "main.h"

/**
* nosequees - prints ???
 */

int nosequees()
{
        char *comando = NULL;
        size_t largo = 0;
        char **args = NULL;
        char *token = strtok(comando, " ");
	int num_tokens, i;

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

                while (token != NULL)
                {
                        if (guardar == NULL)
                        {
                                perror("Error con la memoria");
                                free(guardar);
                                return (1);
                        }
                        args = guardar;

                        args[largo] = strdup(token);
                        if (args[largo] == NULL)
                        {
                                perror("Error al guardar token");
                                free(args);
                                return (1);
                        }
                        largo++;
                        token = strtok(NULL, " ");
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
