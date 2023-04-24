#include "main.h"

/**
 * get_specifier - function
 *
 * @s: param
 * Return: return the function
 */
int (*get_specifier(char s))(va_list ar, params_t *params)
{
	int i;
	specifier_t specifiers[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', NULL},
		{'i', NULL},
		{'b', NULL},
		{'u', NULL},
		{'o', NULL},
		{'x', NULL},
		{'X', NULL},
		{'S', NULL},
		{'p', NULL},
		{'r', NULL},
		{'R', NULL}};

	for (i = 0; i < 13; i++)
	{
		if (specifiers[i].spec == s)
			return (specifiers[i].f);
	}

	return (NULL);
}
