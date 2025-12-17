#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/**
* main - super simple shell
*
* Return: 0
*/

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	char *argv[2];

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			printf("\n");
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		if (pid == 0)
		{
			argv[0] = line;
			argv[1] = NULL;
			execve(line, argv, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	return (0);
}
