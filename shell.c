#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


/**
 * strconcat - concatenates strings
 * @pre_str: string to be added to the /bin/
 * @dest: variable defined outside this function
 * Return: the variable dest
 */
char *strconcat(char *pre_str, char *dest)
{
	char str1[] = "/bin/";
	char str3[100];
	int i = 0, j = 0;

	while (str1[i] != '\0')
	{
		str3[j] = str1[i];
		i++;
		j++;
	}
	i = 0;
	while (pre_str[i] != '\0')
	{
		str3[j] = pre_str[i];
		i++;
		j++;
	}
	str3[j] = '\0';
	strcpy(dest, str3);
	return (dest);
}

/**
 * main - the main shell function
 * Return: always 0
 */

int main(void)
{
	size_t len = 0;
	char *args = NULL;
	ssize_t line;
	char *tokens;
	char *dest;
	int id, i = 0;
	char *envp[] = {(char *)"PATH=/", NULL};

	while (1)
	{
		prompt();

		line = getline(&args, &len, stdin);
		fflush(stdin);

		if (line == -1)
			perror("Error");

		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}

		char *argv[line];

		tokens = strtok(*argv, " ");

		while (tokens != NULL)
		{
			argv[i++] = tokens;
			tokens = strtok(NULL, "\n");
		}

		dest = strconcat(argv[0], dest);
		id = fork();
		if (id == 0)
		{
			execve(dest, argv, envp);
			if (execve(dest, argv, envp) == -1)
				perror("Error");
		}
		else if (id == -1)
			printf("Could not create child process.");
		else
			wait(&id);

		if (strcmp(dest, "exit") == 0)
			break;
	}
	return (0);
}
