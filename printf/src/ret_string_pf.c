/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_string_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:37:25 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/04/29 21:37:12 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		put_str_pf(t_tab *a, char *string)
{
	if (a->obel_x[5] == 0 || a->obel_x[5] == -1)
	{
		write(1, a->mass, a->count_m);
		write(1, string == NULL ? "(null)" : string, a->len_num);
	}
	else if (a->obel_x[5] != 1)
		write(1, string == NULL ? "(null)" : string, a->len_num);
	else
	{
		write(1, string == NULL ? "(null)" : string, a->len_num);
		write(1, a->mass, a->count_m);
	}
}

t_tab		*ret_string_pf(t_tab *a, char *string)
{
	zero_val(a);
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
