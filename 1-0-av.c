#include <stdio.h>
#include <unistd.h>

/**
 * av - prints all arguments from argv
 * @argv: array of argument strings
 *
 * Return: 0
 */
int av(char *argv[])
{
	int i = 0;

	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	return (0);
}

