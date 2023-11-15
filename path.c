#include "shell.h"
/**
 * _getpath - fetch path of function
 * @cmd: a string
 * Return: a string
 */
char *_getpath(char *cmd)
{
	char *path_env, *fulcmd, *dir;
	int i = 0;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
			{
				return (_strdup(cmd));
			}
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		fulcmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (fulcmd)
		{
			_strcpy(fulcmd, dir);
			_strcat(fulcmd, "/");
			_strcat(fulcmd, cmd);
			if (stat(fulcmd, &st) == 0)
			{
				free(path_env);
				return (fulcmd);
			}
			free(fulcmd), fulcmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
