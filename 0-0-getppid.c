#include <stdio.h>
#include <unistd.h>

/**
 * get_ppid - prints the PID of the parent process
 *
 * Return: 0
 */
int get_ppid(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%u\n", (unsigned int)ppid);

	return (0);
}
