#include "shell.h"
/**
 * tokenizer - delimiter
 * @line: a string with a delimitres
 * Return: null
 */
char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **cmd = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	cmd = malloc(sizeof(char *) * (cpt + 1));

	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	if (token == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
