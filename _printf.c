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
	char *p, *start;

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
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, ar);
		p = get_precision(p, &params, ar);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(*p))
			sum += print_from_to(start, p,
								 params.l_mod || params.h_mod ? p - 1 : 0);

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
