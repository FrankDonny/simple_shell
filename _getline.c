ssize_t _getline(char **restrict line, size_t *restrict len, FILE *restrict stream)
{
	char chunk[128];

	if (line == NULL || len == NULL)
	{
		fputs("Error, bad arguments.\n", stderr);
		return (-1);
	}
	if (stream == NULL)
	{
		fputs("Error, bad FILE pointer.\n", stderr);
		return (-1);
	}

	if (*line == NULL)
	{
		*len = sizeof(chunk);
		if ((*line = malloc(*len)) == NULL)
		{
			perror("Unable to allocate memory for the line buffer.\n");
			return (-1);
		}
	}
	(*line)[0] = '\0';

	while (fgets(chunks, sizeof(chunk), stream) != NULL)
	{
		if (*len - strlen(*line) < sizeof(chunk))
		{
			*len *= 2;
			if (*line = realloc(*line, *len) == NULL)
			{
				perror("Unable to reallocate memory to the line buffer.");
				free(line);
				return (-1);
			}
		}
		strcat(*line, chunk);

		if ((*line)[strlen(*line) - 1] == '\n')
		{
			return (strlen(*len));
		}
	}

	return (-1);
}
