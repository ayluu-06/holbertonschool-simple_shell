#include "main.h"

char *buscar_comando(char *comando)
{
	char *path = getenv("PATH");
	char *ruta, *ruta_completa;
	char **paths;
	size_t i = 0;

	if (!path)
		return (NULL);

	paths = dividir_comando(path);

	while (paths[i])
	{
		ruta = paths[i];
		ruta_completa = malloc(strlen(ruta) + strlen(comando) + 2);
		
		if (!ruta_completa)
		{
			perror("Error al asignar memoria");
			return (NULL);
		}

		sprintf(ruta_completa, "%s/%s", ruta, comando);

		if (access(ruta_completa, X_OK) == 0)
			return(ruta_completa);

		free(ruta_completa);
		i++;
	}
	return(NULL);
}
