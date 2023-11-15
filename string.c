#include "shell.h"

/**
 * _strdup - duplicate strings
 * @str: the given string
 * Return: (fail) return a null pointer
 * (success) pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}
/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 * Return: (success) a positive number
 * (fail) a negative number
 */
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}

/**
 * _strlen - finds the length of a given string
 * @s: the given string
 * Return:(success) length of a string
 *
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strcat - concatenates two string in a path form
 * @dest: the first given destination
 * @src: given source
 * Return: concatnate success or fail if it fail
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}
/**
 * _strcpy - copies two strings
 * @dest: destination
 * @src: source
 * Return: success or fail
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

