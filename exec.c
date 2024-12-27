#include <stdio.h>
#include <unistd.h>

/**
 * run_execve - execve example
 *
 * Return: Always 0.
 */
int run_execve(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error executing the command:");
	}
	printf("After execve\n");
	return (0);
}
