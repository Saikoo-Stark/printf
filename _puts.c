#include "main.h"

/**
 * _puts - function
 *
 * @str: param
 * Return: int of length
 */
int _puts(char *str)
{
	int i = 0;

	while (*(str + i))
	{
		_putchar(*(str + i));
		i++;
	}
	return (i);
}

/**
 * _putchar - function
 *
 * @c: param
 * Return: int of length
 */
int _putchar(int c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == -1 || i >= BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != -1)
		buf[i++] = c;

	return (1);
}
