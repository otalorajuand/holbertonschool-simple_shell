#include "main.h"

/**
 * main - execute the command given by user
 * Return: Always 0.
 */

int main(void)
{
	char *buffer = NULL, *arguments[10] = {NULL};
	int i = 0, checkstat = 0, status = 0;
	void (*ptr)(void);
	char *token = NULL, str[BUFSIZ];

	do {
		buffer = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		buffer = read_prompt(buffer);   /* first malloc with getline */
		EXIT(buffer, status);
		ptr = get_built_in(buffer);
		if (ptr != NULL)
		{
			ptr();  /* executes the function */
		}
		strcpy(str, buffer);
		token = strtok(str, " "); /* just the first word */

		if (token == NULL)
		{
			free(buffer);
			continue;
		}
		arguments[0] = token;
		i = 1;
		while (token != NULL)
		{
			token = strtok(NULL, " "); /* rest of words */
			arguments[i] = token;
			i++;
		}
		free(buffer);
		checkstat = check_stat(arguments);
		if (checkstat == 0)
		{
			status = create_child(arguments);
		}
	} while (buffer != NULL);
	return (WEXITSTATUS(status));
}
