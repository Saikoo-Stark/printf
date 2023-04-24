#include "main.h"

int (*get_specifier)(va_list ar, params_t *params)
{
	int i;
	specifier_t specifiers = {
		{'c', NULL},
		{'s', NULL},
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
		{'R', NULL}
	}

	for (i = 0; i < 13; i++)
	{
		if (specifiers[i].spec ==)
	}
}
