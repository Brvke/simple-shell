#include "shell.h"
/**
 * _itoa - changes an int into string
 * @value: to be changed to int
 *
 * Return: a string output
 */
char *_itoa(int value)
{
	int str_size;
	char *str;
	int ne = 0;
	int i = 0;
	int num_dig = 0;
	int temp;
	int start;
	int end;

	if (value == 0)
	{
		str = (char *) malloc(2 * sizeof(char));

		if (str == NULL)
			return (NULL);

		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (value < 0)
	{
		ne = 1;
		value = -value;
	}
	temp = value;
	while (temp != 0)
	{
		temp /= 10;
		num_dig++;
	}
	str_size = num_dig + ne + 1;
	str = (char *)malloc(str_size * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (value != 0)
	{
		int remainder = value % 10;

		str[i++] = remainder + '0';
		value /= 10;
	}
	if (ne)
		str[i++] = '-';
	str[i] = '\0';
	start = ne;
	end = i - 1;
	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}
