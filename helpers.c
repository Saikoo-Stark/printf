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
		{"c", print_c},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13}};

	for (i = 0; i < 13; i++)
	{
		if (*specifiers[i].spec == s)
			return (specifiers[i].f);
	}

	return (NULL);
}

/**
 * get_precision - gets the precision from the format stringfunction
 * @p: param
 * @params: param
 * @ar: param
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ar)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ar, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->prec = d;
	return (p);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case '+':
		i = params->plus_f = 1;
		break;
	case ' ':
		i = params->space_f = 1;
		break;
	case '#':
		i = params->hash_f = 1;
		break;
	case '-':
		i = params->minus_f = 1;
		break;
	case '0':
		i = params->zero_f = 1;
		break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->h_mod = 1;
		break;
	case 'l':
		i = params->l_mod = 1;
		break;
	}
	return (i);
}

/**
 * get_width - func
 * @s: param
 * @params: param
 * @ap: the param
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
