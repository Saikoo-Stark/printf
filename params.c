#include "main.h"

/**
 * init_params - function
 *
 * @params: param
 */
void init_params(params_t *params)
{
	params->unsign = 0;
	params->plus_f = 0;
	params->space_f = 0;
	params->hash_f = 0;
	params->zero_f = 0;
	params->minus_f = 0;
	params->width = 0;
	params->prec = UINT_MAX;
	params->h_mod = 0;
	params->l_mod = 0;
}
