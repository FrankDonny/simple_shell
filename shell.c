#include "main.h"

/**
 * main - the main shell function
 * Return: always 0
 */

int main(void)
{
	size_t buf_size = 1024;
	ssize_t line;
	char *buffer = malloc(sizeof(char) * buf_size);;
	char *tokens;
	int id, i;
	char *envp[] = {"SHELL=/bin/bash", NULL};

	while (1)
	{
		prompt();

		line = getline(&buffer, &buf_size, stdin);

		char *argv[line + 1];

		tokens = strtok(buffer, " ");

		while (tokens != NULL)
		{
			argv[i++] = strdup(tokens);
			tokens = strtok(NULL, "\n");
		}

		id = fork();
		if (id != 0)
			wait(NULL);
		else
		{
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("Error");
			}	
			strcat("/bin/", argv[0]);
			execve(argv[0], argv, envp);
		}
		if (strcmp(argv[0], "exit") == 0)
			break;
	}
	free(buffer);
	return (0);
}
