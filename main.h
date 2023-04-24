#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#define INIT_PARAMS                  \
	{                                \
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
	}
#define BUF_SIZE 1024

/* structs */

/**
 * struct Params - struct
 *
 * @unsign: param
 * @plus_f: param
 * @unsign: param
 * @space_f: param
 * @hash_f: param
 * @zero_f: param
 * @minus_f: param
 * @width: param
 * @prec: param
 * @h_mod: param
 * @l_mod: param
 */
typedef struct Params
{
	unsigned int unsign;
	unsigned int plus_f;
	unsigned int space_f;
	unsigned int hash_f;
	unsigned int zero_f;
	unsigned int minus_f;
	unsigned int width;
	unsigned int prec;
	unsigned int h_mod;
	unsigned int l_mod;

} params_t;

/**
 * struct Specifier - struct
 *
 * @spec: param
 * @f: param
 */
typedef struct Specifier
{
	char spec;
	int (*f)(va_list, params_t *);
} specifier_t;

/* functions*/
void init_params(params_t *);
int (*get_specifier(char s))(va_list ar, params_t *params);
int _puts(char *str);
int _putchar(int c);

int print_c(va_list ar, params_t *params);
int print_s(va_list ar, params_t *params);

int _printf(const char *format, ...);

#endif
