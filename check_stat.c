#include "main.h"

int check_stat(char **arguments)
{
	struct stat st;
	int res = 0;

	if (stat(arguments[0], &st) != 0)
	{
		res = 1;
		write(STDOUT_FILENO, "/shell: No such file or directory\n", 35);
	}
	return(res);
}
