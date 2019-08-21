/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:43:49 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/14 13:13:44 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long int	pr_max_val_pf(t_tab *a, long long int num)
{
	a->int_max = -9223372036854775807;
	if (num == a->int_max - 1)
	{
		a->full = 1;
		num++;
	}
	num *= -1;
	return (num);
}

void			hex_chec_len_pf(t_tab *a)
{
	a->zero = a->obel_x[8] - a->len_num;
	if (a->zero < 0)
		a->zero = 0;
	a->space = a->obel_x[6] - (a->len_num + a->zero + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->zero + a->len_num + a->space;
}

void			hex_check_fl_pf(t_tab *a)
{
	if (a->obel_x[3] == 1)
	{
		a->sig = 2;
		a->sym = a->obel_x[10] == 7 ? 'x' : 'X';
	}
}

void			check_sig_pf(t_tab *a, long long int num)
{
	if (num < 0)
	{
		a->sym = '-';
		a->sig = 1;
	}
	if (num >= 0)
	{
		if (a->obel_x[4] == 1)
		{
			a->sym = ' ';
			a->sig = 1;
		}
		if (a->obel_x[4] == 2)
		{
			a->sym = '+';
			a->sig = 1;
		}
	}
}

void			zero_val_pf(t_tab *a)
{
	a->sig = 0;
	a->len = 0;
	a->full = 0;
	a->zero = 0;
	a->stop = 0;
	a->space = 0;
	a->len_num = 0;
	a->count_m = 0;
	a->sym = ' ';
	a->mass = NULL;
}
