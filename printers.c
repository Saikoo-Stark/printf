#include "main.h"

int print_c(va_list ar, params_t *params)
{
	(void)params;
	return (_putchar(va_arg(ar, int)));
}

int print_s(va_list ar, params_t *params)
{
	(void)params;
	return (_puts(va_arg(ar, char *)));
}
