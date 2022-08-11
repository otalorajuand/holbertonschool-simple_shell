#include "main.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */

int main(void)
{
	int status, size_len;
	pid_t pid_child;
	size_t bufsize = BUFSIZ;
	char *buffer, *arguments[] = {NULL, NULL};
	struct stat st;

		if (!isatty(STDIN_FILENO)) 
		{
			getline(&buffer, &bufsize, stdin);
			size_len = strlen(buffer);
			buffer[size_len - 1] = '\0';
			if (stat(buffer, &st) == 0) 
			{
				arguments[0] = buffer;
				exit(execve(arguments[0], arguments, NULL));
				perror("Error:");
			}
			else
				exit(write(STDOUT_FILENO, "/shell: No such file or directory\n", 35));
		}
	while (1)
	{
		pid_child = fork();
		if (pid_child > 0)
		{
			wait(&status);
		}
		else if (pid_child == 0)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 10);
			getline(&buffer, &bufsize, stdin);
			size_len = strlen(buffer);
			buffer[size_len - 1] = '\0';
			if (stat(buffer, &st) == 0) 
			{
				arguments[0] = buffer;
				exit(execve(arguments[0], arguments, NULL));
				perror("Error:");
			}
			else
				exit(write(STDOUT_FILENO, "/shell: No such file or directory\n", 35));
		}
	}
	return (0);
}
