#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - compare envp and environ
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variables
 *
 * Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	int i;

	(void)argc;
    (void)argv;

	printf("Address of envp:     %p\n", (void *)envp);
	printf("Address of environ: %p\n\n", (void *)environ);

	printf("First 3 environment variables via envp:\n");
	for (i = 0; i < 3 && envp[i] != NULL; i++)
		printf("%s\n", envp[i]);

	printf("\nFirst 3 environment variables via environ:\n");
	for (i = 0; i < 3 && environ[i] != NULL; i++)
		printf("%s\n", environ[i]);

	return (0);
}
