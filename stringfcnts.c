#include "simple_shell.h"

/**
 *strcpy - copies string from src to dest
 *@dest: destination of copied string
 *@src: source of the copied string
 *
 *Return: copy
 */
char *strcpy(char *dest, const char *src)
{
	char *copy = dest;

	while ((*dest++ = *src++))
		;
	return (copy);
}

/**
 *strcat - concatenates a string
 *@dest: destination
 *@str: string
 *
 *Return: concatenated string
 */
char *strcat(char *dest, const char *str)
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
 *strcmp - compares strings
 *@str1: first string to compare
 *@str2: second string to compare to
 *
 *Return: 0 - if equal
 * - if str1 is less than str2
 * + if str1 is greater than str2
 */
int strcmp(const char *str1, const char str2)
{
	while (*str1 && (*str1 == str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
