#include "main.h"

/**
 * print_hex - function
 * @ar: param
 * @params: param
 *
 * Return: bytes printed
 */
int print_hex(va_list ar, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_mod)
		l = (unsigned long)va_arg(ar, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ar, unsigned int);
	else
		l = (unsigned int)va_arg(ar, unsigned int);

	str = convert(l, 16, UNSIGNED | LOWERCASE, params);
	if (params->hash_f && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_HEX - function
 * @ar: param
 * @params: param
 *
 * Return: bytes printed
 */
int print_HEX(va_list ar, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_mod)
		l = (unsigned long)va_arg(ar, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ar, unsigned int);
	else
		l = (unsigned int)va_arg(ar, unsigned int);

	str = convert(l, 16, UNSIGNED, params);
	if (params->hash_f && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_binary - function
 * @ar: param
 * @params: param
 *
 * Return: bytes printed
 */
int print_binary(va_list ar, params_t *params)
{
	unsigned int n = va_arg(ar, unsigned int);
	char *str = convert(n, 2, UNSIGNED, params);
	int c = 0;

	if (params->hash_f && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_mod)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, UNSIGNED, params);

	if (params->hash_f && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
