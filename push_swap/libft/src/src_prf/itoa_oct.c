/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 12:25:49 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/14 13:13:35 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

void	oct_num_zero_pf(t_tab *a, unsigned long long int num)
{
	a->zero = a->obel_x[6] - (a->len_num + a->sig);
	if (a->zero < 0)
		a->zero = 0;
	a->len = a->zero + a->sig + a->len_num;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->zero;
	put_zero_pf(a);
	if (a->obel_x[3] == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop += (a->len_num + a->sig) - 1;
	oct_put_num_pf(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}

void	oct_null_pf(t_tab *a)
{
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
	write(1, a->mass, a->len);
	free(a->mass);
}

void	other_oct_pf(t_tab *a, unsigned long long int num)
{
	a->zero = a->obel_x[8] - (a->sig + a->len_num);
	if (a->zero < 0)
		a->zero = 0;
	a->space = a->obel_x[6] - (a->sig + a->zero + a->len_num);
	if (a->space < 0)
		a->space = 0;
	a->len = (a->space + a->zero + a->sig + a->len_num);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->space;
	put_space_pf(a);
	a->stop += a->zero;
	put_zero_pf(a);
	if (a->obel_x[3] == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop += (a->len_num + a->sig) - 1;
	oct_put_num_pf(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}

t_tab	*itoa_oct_pf(t_tab *a, unsigned long long int num)
{
	zero_val_pf(a);
	a->len_num = numlen_sig_pf(num, 8);
	if (a->obel_x[3] == 1 && num != 0)
	{
		a->sym = '0';
		a->sig = 1;
	}
	if (num == 0 && a->obel_x[8] == 0)
	{
		oct_null_pf(a);
		return (a);
	}
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		oct_num_zero_pf(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		oct_left_al_pf(a, num);
		return (a);
	}
	other_oct_pf(a, num);
	return (a);
}
