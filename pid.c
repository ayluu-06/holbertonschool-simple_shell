#include <stdio.h>
#include <unistd.h>

/**
 * getpid - PID
 *
 * Return: Always 0.
 */
int getpid(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}
