#include "main.h"

/**
 * _printf - a printf function
 *
 * @format: param
 *
 * Return: num of chars
 */

int _printf(const char *format, ...)
{
	va_list ar;
	unsigned int sum = 0;
	params_t params = INIT_PARAMS;

	va_start(ar, format);
}
