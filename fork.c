#include <stdio.h>
#include <unistd.h>

/**
 * fork - fork example
 *
 * Return: Always 0.
 */
int fork(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("Before fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error in fork:");
		return (1);
	}
	printf("After fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
	return (0);
}
