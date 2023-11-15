#include "shell.h"
/**
 * freearray - frees dynamically allocated memory
 * @arr: double pointer to be freed
 */
void freearray(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		if (arr[i])
			free(arr[i]);
		arr[i] = NULL;
	}

	free(arr), arr = NULL;
}

/**
 * p_error - prints error
 * @dis: string
 * @cmd: string
 * @idx: integer
 */
void p_error(char *dis, char *cmd, int idx)
{
	char *index, masg[] = ": not found";

	index = _itoa(idx);
	
	write(STDERR_FILENO, dis, _strlen(dis));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, masg, _strlen(masg));

	free(index);
}

/**
 * reverse_string - reverse a string
 * @str:
 * @len:
 * Return: reverse string
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * is_posnum - checks if a string is positive
 * @str: string
 * Return: 1 if success
 */
int is_posnum(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - changes string to int
 * @str: int
 * Return: int value
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
