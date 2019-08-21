/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_sig_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:38:06 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/04/29 21:30:49 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_num(t_tab *a, unsigned long long int num)
{
	while (num > 9)
	{
		if (a->full == 1)
		{
			a->mass[a->stop] = (num % 10) + '1';
			a->stop--;
			a->count_m++;
			num /= 10;
		}
		a->mass[a->stop] = (num % 10) + '0';
		a->stop--;
		a->count_m++;
		num /= 10;
	}
	if (num < 10)
	{
		a->mass[a->stop] = (num % 10) + '0';
		a->count_m++;
	}
}

void	put_zero(t_tab *a)
{
	while (a->count_m < a->stop)
	{
		a->mass[a->count_m] = '0';
		a->count_m++;
	}
}

void	put_space(t_tab *a)
{
	while (a->count_m < a->stop)
	{
		a->mass[a->count_m] = ' ';
		a->count_m++;
	}
}

void	other_put(t_tab *a, unsigned long long int num)
{
	a->len_num = numlen_sig_pf(num, 10);
	left_al_var(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->space;
	put_space(a);
	if (a->sym == '-' || a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop += (a->sig + a->zero);
	put_zero(a);
	a->stop += (a->len_num - 1);
	put_num(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}

t_tab	*itoa_sig_dec(t_tab *a, long long int num)
{
	zero_val(a);
	check_sig(a, num);
	if (num == 0 && a->obel_x[8] == 0)
	{
		num_zero(a);
		return (a);
	}
	if (num < 0)
		num = pr_max_val(a, num);
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		flag_zero(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		left_al(a, num);
		return (0);
	}
	other_put(a, num);
	return (a);
}
