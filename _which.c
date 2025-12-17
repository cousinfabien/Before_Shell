#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * find_in_path - looks for a file in the directories of PATH
 * @filename: the file to search
 * @path: the PATH environment variable
 *
 * Return: full path if found (malloc'ed), NULL otherwise
 */
char *find_in_path(char *filename, char *path)
{
	char *token, *path_copy, *full_path;

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	full_path = malloc(1024);
	if (!full_path)
	{
		free(path_copy);
		return (NULL);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		snprintf(full_path, 1024, "%s/%s", token, filename);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	free(full_path);
	return (NULL);
}

/**
 * main - looks for files in the current PATH
 * @argc: number of arguments
 * @argv: array of filenames
 *
 * Return: 0 on success, 1 if any file not found
 */
int main(int argc, char *argv[])
{
	int i;
	char *path, *found_path;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "PATH not set\n");
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		if (strchr(argv[i], '/'))
		{
			if (access(argv[i], X_OK) == 0)
				printf("%s\n", argv[i]);
			else
				fprintf(stderr, "%s: not found\n", argv[i]);
			continue;
		}

		found_path = find_in_path(argv[i], path);
		if (found_path)
		{
			printf("%s\n", found_path);
			free(found_path);
		}
		else
			fprintf(stderr, "%s: not found\n", argv[i]);
	}

	return (0);
}
