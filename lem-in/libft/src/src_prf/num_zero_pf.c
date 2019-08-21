/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_zero_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:46:25 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/07/21 13:38:35 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	num_zero_pf(t_tab *a)
{
	if (a->obel_x[5] == 1)
	{
		num_zero_left_pf(a);
		return ;
	}
	num_zero_null_pf(a);
}

void	num_zero_null_pf(t_tab *a)
{
	a->space = a->obel_x[6] - a->sig;
	if (a->space < 0)
		a->space = 0;
	a->len = a->space + a->sig;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->space;
	put_space_pf(a);
	if (a->obel_x[4] >= 1)
		a->mass[a->count_m] = a->sym;
	write(1, a->mass, a->len);
	free(a->mass);
}

int		numlen_sig_pf(unsigned long long int num, size_t base)
{
	int	len;

	len = 1;
	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

void	oct_left_al_pf(t_tab *a, unsigned long long int num)
{
	a->zero = a->obel_x[8] - (a->len_num + a->sig);
	if (a->zero < 0)
		a->zero = 0;
	a->space = a->obel_x[6] - (a->len_num + a->zero + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->space + a->len_num + a->sig + a->zero;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->zero;
	put_zero_pf(a);
	if (a->sig == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop += (a->len_num + a->sig) - 1;
	oct_put_num_pf(a, num);
	a->stop = a->count_m + a->space;
	put_space_pf(a);
	write(1, a->mass, a->len);
	num = num + 1;
	free(a->mass);
}

void	oct_null_pf(t_tab *a)
{
	if (a->obel_x[6] < 1 && a->obel_x[3] == 1 && a->obel_x[8] == 0)
		a->obel_x[6] = 1;
	a->space = a->obel_x[6] - a->sig;
	if (a->space < 0)
		a->space = 0;
	a->len = a->space + a->sig;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->obel_x[5] == 1 && a->sig == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
		a->sig = 0;
	}
	a->stop = (a->space + 1) - a->sig;
	put_space_pf(a);
	if (a->sig == 1)
		a->mass[a->count_m] = a->sym;
	if (a->obel_x[3] == 1 && a->obel_x[8] == 0)
		a->mass[a->len - 1] = '0';
	write(1, a->mass, a->len);
	free(a->mass);
}
