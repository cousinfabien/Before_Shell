#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* On peut réutiliser _getenv si tu veux */
extern char **environ;

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: pointer to the value string, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i;
	size_t len;

	if (!name)
		return (NULL);

	len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
	}
	return (NULL);
}

/**
 * print_path_dirs - prints each directory in PATH
 */
void print_path_dirs(void)
{
	char *path, *token, *path_copy;

	path = _getenv("PATH");
	if (!path)
	{
		printf("PATH not found\n");
		return;
	}

	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("strdup");
		return;
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}

	free(path_copy);
}

/* Example main to test */
int main(void)
{
	print_path_dirs();
	return (0);
}
