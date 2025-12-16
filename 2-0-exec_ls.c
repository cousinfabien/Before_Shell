#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
* main - execute five times ls -l /tmp
*
* Return: 0
*/

int main(void)
{
	int i;
	pid_t pid;
	int status;
	char *argv[] = {"ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (1);
		}

		if (pid == 0)
		{
			if (execve("/bin/ls", argv, NULL) == -1)
			{
				perror("execve");
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
