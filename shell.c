#include "main.h"

/**
 * main - the main shell function
 * Return: always 0
 */

int main(void)
{
	size_t buf_size = 64;
	ssize_t line;
	char *buffer = malloc(sizeof(char) * buf_size);;
	char *tokens;
	int id, i;
	char *envp[] = {(char *) "PATH=/bin", 0};

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
		strcat("/bin/", argv[0]);

		id = fork();
		if (id != 0)
			wait(NULL);
		else
		{
			/*strcat("/bin/", argv[0]);*/
                        execve(argv[0], argv, envp);

			if (execve(argv[0], argv, envp) == -1)
			{
				perror("./Shell");
			}	
			/*strcat("/bin/", argv[0]);*/
		}
		if (strcmp(argv[0], "exit") == 0)
			break;
	}
	free(buffer);
	return (0);
}
