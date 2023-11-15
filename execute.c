#include "shell.h"

/**
 * _execute - execute a command and its argument
 * @cmd: pointer to tokenized user input
 * @argv: pointer to main input
 * @idx: pointer to main input
 *
 * Return: 0 if success
 */
int _execute(char **cmd, char **argv, int idx)
{
	char *fulcmd;
	pid_t child;
	int stat;

	fulcmd = _getpath(cmd[0]);
	if (!fulcmd)
	{
		p_error(argv[0], cmd[0], idx);
		freearray(cmd);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(fulcmd, cmd, environ) == -1)
		{
			free(fulcmd), fulcmd = NULL;
			freearray(cmd);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		free(fulcmd), fulcmd = NULL;
		if (cmd)
			freearray(cmd);
	}
	return (WEXITSTATUS(stat));
}
