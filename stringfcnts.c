#include "simple_shell.h"

/**
 *_strcpy - copies string from src to dest
 *@dest: destination of copied string
 *@src: source of the copied string
 *
 *Return: copy
 */
char *_strcpy(char *dest, const char *src)
{
	char *copy = dest;

	while ((*dest++ = *src++))
		;
	return (copy);
}

/**
 *_strcat - concatenates a string
 *@dest: destination
 *@src: source
 *
 *Return: concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	char *cat = dest;

	while (*dest)
		dest++;
	while ((*dest++ = *src++))
		;
	return (cat);
}

/**
 *string_length - returns length of size_t string
 *@str: string to get length of
 *
 *Return: length of said string
 */
size_t string_length(const char *str)
{
	const char *s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

/**
 *_strcmp - compares strings
 *@str1: first string to compare
 *@str2: second string to compare to
 *
 *Return: 0 - if equal
 * - if str1 is less than str2
 * + if str1 is greater than str2
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/**
 *_strncmp - compares two strings upto a specified number of characters
 *@s1: It is a pointer to the first string to be compared.
 *@s2: It is a pointer to the second string to be compared.
 *@c: It specifies the maximum number of characters to compare.
 *
 *Return: 0 on success
 *- s1 < s2
 *+ s1 > s2
 */
int _strncmp(const char *s1, const char *s2, size_t c)
{
	while (c > 0)
	{
		if (*s1 != *s2)
	{
		return (*s1 - *s2);
	}
		if (*s1 == '\0')
		{
			break;
		}
		s1++;
		s2++;
		c--;
	}
	return (0);
}
