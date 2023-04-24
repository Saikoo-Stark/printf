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
	char *p;

	va_start(ar, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		p++;
		if (*p == '%')
		{
			sum += _putchar('%');
		}

		if (get_specifier((char)*p))
		{
			int (*fun)(va_list, params_t *) = get_specifier((char)*p);

			sum += fun(ar, &params);
		}
	}
	_putchar(-1);
	va_end(ar);
	return (sum);
}
