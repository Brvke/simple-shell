#include "shell.h"
/**
 * _getpath - fetch path of function
 * @cmd: a string
 * Return: a string
 */
char *_getpath(char *cmd)
{
	char *path_env, *fulcmd, *dir;
	/*int i = 0;*/
	/*int cmd_len = _strlen(cmd);*/
	/*struct stat st;*/
/*
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
	}*/
	path_env = _getenv("PATH");
	/*if (!path_env)
		return (NULL);*/
	dir = strtok(path_env, ":");
	/*while (dir)
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
}*/
	while (dir != NULL)
	{
		fulcmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		write(*fulcmd, dir, _strlen(dir));
		write(*fulcmd, "/", 1);
		write(*fulcmd, cmd, _strlen(cmd));
	if (access(fulcmd, X_OK) == 0)
	{
		return (fulcmd);
	}
	free(fulcmd);
	dir = strtok(NULL, ":");
	}
	return (NULL);
}


