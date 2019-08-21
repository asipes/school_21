/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_num_zero_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:18:12 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:38:30 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	oct_put_num_pf(t_tab *a, unsigned long long int num)
{
	while (num > 7)
	{
		a->mass[a->stop] = (num % 8) + '0';
		a->stop--;
		a->count_m++;
		num /= 8;
	}
	if (num < 8)
	{
		a->mass[a->stop] = (num % 8) + '0';
		a->count_m++;
	}
}

void	other_char_pf(t_tab *a, char c)
{
	a->space = a->obel_x[6];
	a->mass = ft_strnew(a->space);
	a->abs_len += a->space;
	a->stop = a->space - 1;
	put_space_pf(a);
	a->mass[a->count_m] = c;
	write(1, a->mass, a->space);
	free(a->mass);
}

void	other_float_pf(t_tab *a)
{
	a->space = a->obel_x[6] - (a->len_num + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->space;
	a->mass = ft_strnew(a->len);
	a->stop = a->space;
	put_space_pf(a);
	if (a->sig == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	write(1, a->mass, a->len);
	write(1, a->arr, a->len_num);
	a->abs_len += (a->len + a->len_num);
	free(a->arr);
	free(a->mass);
}

void	other_hex_pf(t_tab *a, unsigned long long int num)
{
	hex_chec_len_pf(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->space;
	put_space_pf(a);
	if (a->sig == 2)
	{
		a->mass[a->count_m] = '0';
		a->mass[a->count_m + 1] = a->sym;
		a->count_m += 2;
	}
	a->stop += a->sig + a->zero;
	put_zero_pf(a);
	a->stop += (a->len_num - 1);
	hex_put_num_pf(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}
