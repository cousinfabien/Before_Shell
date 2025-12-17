#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - prints the environment variables
 *
 * Return: 0
 */
int main(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}
