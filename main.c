#include "shell.h"

/**
 * main - entry point
 * @ac: argument count
 * @argv: array of argument
 * Return: loop
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int stat;
	int idx = 0;
	(void) ac;
	(void) argv;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		idx++;
		cmd = tokenizer(line);
		if (!cmd)
			continue;
		if (_builtin(cmd[0]))
			hbuiltin(cmd, argv, stat, idx);
		else
			stat = _execute(cmd, argv, idx);
		if (line)
			free(line);
	}
}
