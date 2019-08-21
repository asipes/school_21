/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_check_fl_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:15:42 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:38:56 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	hex_check_fl_pf(t_tab *a)
{
	if (a->obel_x[3] == 1)
	{
		a->sig = 2;
		a->sym = a->obel_x[10] == 7 ? 'x' : 'X';
	}
}

void	hex_left_al_pf(t_tab *a, unsigned long long int num)
{
	hex_chec_len_pf(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->sig == 2)
	{
		a->mass[a->count_m] = '0';
		a->mass[a->count_m + 1] = a->sym;
		a->count_m += 2;
	}
	a->stop = a->sig + a->zero;
	put_zero_pf(a);
	a->stop += a->len_num - 1;
	hex_put_num_pf(a, num);
	a->stop = a->count_m + a->space;
	put_space_pf(a);
	write(1, a->mass, a->len);
	free(a->mass);
}

void	hex_null_pf(t_tab *a)
{
	a->space = a->obel_x[6];
	if (a->space < 0)
		a->space = 0;
	a->mass = ft_strnew(a->space);
	a->abs_len += a->space;
	a->stop = a->space;
	put_space_pf(a);
	write(1, a->mass, a->space);
	free(a->mass);
}

void	hex_num_zero_pf(t_tab *a, unsigned long long num)
{
	a->zero = a->obel_x[6] - (a->len_num + a->sig);
	if (a->zero < 0)
		a->zero = 0;
	a->len = a->sig + a->zero + a->len_num;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->sig == 2)
	{
		a->mass[a->count_m] = '0';
		a->mass[a->count_m + 1] = a->sym;
		a->count_m += 2;
	}
	a->stop = (a->sig + a->zero);
	put_zero_pf(a);
	a->stop += (a->len_num - 1);
	hex_put_num_pf(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}

void	hex_put_num_pf(t_tab *a, unsigned long long int num)
{
	a->sym = a->obel_x[10] == 7 ? 'a' : 'A';
	while (num > 15)
	{
		a->mass[a->stop] = (num % 16) + (num % 16 > 9 ? a->sym - 10 : '0');
		a->stop--;
		a->count_m++;
		num /= 16;
	}
	if (num < 16)
	{
		a->mass[a->stop] = (num % 16) + (num % 16 > 9 ? a->sym - 10 : '0');
		a->count_m++;
	}
}
