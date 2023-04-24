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
#define LOWERCASE 2
#define UNSIGNED 1
#define NULL_STRING "(null)"

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
	char *spec;
	int (*f)(va_list, params_t *);
} specifier_t;

/* functions*/
void init_params(params_t *);
int (*get_specifier(char s))(va_list ar, params_t *params);
int _puts(char *str);
int _putchar(int c);

int print_c(va_list ar, params_t *params);
int print_s(va_list ar, params_t *params);
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);
char *get_precision(char *p, params_t *params, va_list ap);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

int _printf(const char *format, ...);

#endif
