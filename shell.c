#include "main.h"

/**
 * main - the main shell function
 * Return: always 0
 */

int main(void)
{
	size_t buf_size = 64;
	ssize_t line;
	char *buffer;
	static int first_time = 1;
	int id;
	char *envp[] = {"SHELL=/bin/bash", NULL};

	buffer = malloc(sizeof(char) * buf_size);

	while (1)
	{
		prompt();

		line = getline(&buffer, &buf_size, stdin);

		char *argv[line + 1];

		argv[0] = "/bin/ls";

		id = fork();
		if (id != 0)
			wait(NULL);
		else
		{
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("Error");
			}
		}
		if (strcmp(*argv, "exit") == 0)
			break;
	}
	free(buffer);
	return (0);
}
