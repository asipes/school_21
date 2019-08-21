/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_int_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:26:20 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:38:12 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab					*ret_int_pf(t_tab *a, long long int i)
{
	if (a->obel_x[10] < 4)
	{
		i = non_uns_int_pf(a, i);
		itoa_sig_dec_pf(a, i);
	}
	else
	{
		if (a->obel_x[10] == 5)
			a->obel_x[9] = 2;
		i = this_uns_int_pf(a, i);
		if (a->obel_x[10] == 4 || a->obel_x[10] == 5)
			itoa_oct_pf(a, i);
		if (a->obel_x[10] == 6 || a->obel_x[10] == 23)
			itoa_uns_dec_pf(a, i);
		if (a->obel_x[10] == 7 || a->obel_x[10] == 8)
			itoa_hex_pf(a, i);
	}
	return (a);
}

t_tab					*ret_point_pf(t_tab *a)
{
	if (a->p_point == 0)
	{
		if (a->obel_x[8] == -1)
			a->obel_x[8] = 1;
		if (!(a->po = ft_strnew(a->obel_x[8] + 2)))
			return (memory_error_pf(a));
		a->po[0] = '0';
		a->po[1] = 'x';
		while (a->obel_x[8])
		{
			a->po[a->obel_x[8] + 1] = '0';
			a->obel_x[8]--;
		}
		a->obel_x[8] = -1;
		ret_string_pf(a, a->po);
		free(a->po);
		return (a);
	}
	ret_int_pf(a, a->p_point);
	return (a);
}

t_tab					*ret_string_pf(t_tab *a, char *string)
{
	zero_val_pf(a);
	a->sym = a->obel_x[5] == 0 ? '0' : ' ';
	a->len_num = string == NULL ? 6 : ft_strlen(string);
	a->len_num = (a->obel_x[8] != -1 && a->obel_x[8] < a->len_num) ?
			a->obel_x[8] : a->len_num;
	a->space = a->obel_x[6] - a->len_num;
	a->len = a->obel_x[6] > a->len_num ? a->obel_x[6] : a->len_num;
	if (a->space > 0)
	{
		a->mass = ft_strnew(a->space);
		while (a->space > 0)
		{
			a->mass[a->space - 1] = a->sym;
			a->space--;
			a->count_m++;
		}
	}
	put_str_pf(a, string);
	a->abs_len += a->len;
	if (a->mass)
		free(a->mass);
	return (a);
}

unsigned long long int	this_uns_int_pf(t_tab *a, unsigned long long int i)
{
	if (a->obel_x[9] == -1)
		i = (unsigned int)i;
	if (a->obel_x[9] == 1)
		i = (unsigned long int)i;
	if (a->obel_x[9] == 2)
		i = (unsigned long long int)i;
	if (a->obel_x[9] == 3)
		i = (unsigned int)i;
	if (a->obel_x[9] == 4)
		i = (unsigned short int)i;
	if (a->obel_x[9] == 5)
		i = (unsigned char)i;
	return (i);
}

void					zero_char_pf(t_tab *a, char c)
{
	a->zero = a->obel_x[6];
	a->mass = ft_strnew(a->zero);
	a->abs_len += a->zero;
	a->stop = a->zero - 1;
	put_zero_pf(a);
	a->mass[a->count_m] = c;
	write(1, a->mass, a->zero);
	free(a->mass);
}
