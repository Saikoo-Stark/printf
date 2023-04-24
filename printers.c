#include "main.h"

/**
 * print_c - a printf function
 *
 * @ar: param
 * @params: param
 * Return: num of chars
 */
int print_c(va_list ar, params_t *params)
{
	(void)params;
	return (_putchar(va_arg(ar, int)));
}

/**
 * print_s - a printf function
 *
 * @ar: param
 * @params: param
 * Return: num of chars
 */
int print_s(va_list ar, params_t *params)
{
	(void)params;
	return (_puts(va_arg(ar, char *)));
}
