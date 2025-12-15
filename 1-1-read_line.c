#include <stdio.h>
#include <stdlib.h>

/**
* read_line - prompt that reads a line and print it
*
* Return: 0 on sucess - 1 on failure
*/

int read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			printf("\n");
			break;
		}
		printf("%s", line);
	}

	free(line);
	return (0);
}
