#include "main.h"

char *try_path(char **arguments)
{
	char *aux = NULL, *path = NULL, *token = NULL, str[BUFSIZ];
	struct stat st;

	aux = malloc(sizeof(char) * 1024);

	if (aux == NULL)
		return (NULL);

	path = print_path();
	strcpy(str, path);
	token = strtok(str, ":");
	while (token != NULL)
	{
		strcpy(aux, token);
		strcat(aux, "/");
		strcat(aux, arguments[0]);
		if (stat(aux, &st) == 0)
		{
			free(path);
			return (aux);
		}
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
