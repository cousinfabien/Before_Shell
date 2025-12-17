#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	if (name == NULL)
		return (NULL);

	len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		/* Check if the variable starts with name + '=' */
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return &environ[i][len + 1]; /* return pointer to value */
	}

	return (NULL);
}

/* Example main to test _getenv */
int main(void)
{
	char *val;

	val = _getenv("PATH");
	if (val)
		printf("PATH=%s\n", val);
	else
		printf("PATH not found\n");

	val = _getenv("HOME");
	if (val)
		printf("HOME=%s\n", val);
	else
		printf("HOME not found\n");

	return (0);
}
