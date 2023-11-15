#include "shell.h"

/**
 * _builtin - checks for builtin function
 * @cmd: pointer to tokenized user input
 *
 * Return: 0 if success
 */
int _builtin(char *cmd)
{
	char *builtins[] = {
		"exit", "env", "sentenv",
		"cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * hbuitin - checks for buitin functions
 * @cmd: pointer to tokenized user input
 * @argv: pointer to main input
 * @stat: int data type
 * @idx: int data type
 * Return: 0 if success
 */
void hbuiltin(char **cmd, char **argv, int stat, int idx)
{
	if (_strcmp(cmd[0], "exit") == 0)
		exit_shell(cmd, argv, &stat, idx);

	else if (_strcmp(cmd[0], "env") == 0)
		print_env(cmd, &stat);

}

/**
 * exit_shell - checks for buitin functions
 * @cmd: pointer to tokenized user input
 * @argv: pointer to main input
 * @stat: int data type
 * @idx: int data type
 * Return: 0 if success
 */
void exit_shell(char **cmd, char **argv, int *stat, int idx)
{
	int exit_v = (*stat);
	char *index, masg[] = ": exit: illegaln number: ";

	if (cmd[1])
	{
		if (is_posnum(cmd[1]))
		{
			exit_v = _atoi("0");
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ":", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, masg, _strlen(masg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			freearray(cmd);
			return;
		}
	}
	freearray(cmd);
	exit(exit_v);
}

/**
 * print_env - checks for builtin functions
 * @cmd: pointer to tokenized user input
 * @stat: a pointer to int variables
 * Return: 0 if success
 */
void print_env(char **cmd, int *stat)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(cmd);
	(*stat) = 0;
}
