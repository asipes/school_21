/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 22:41:35 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/14 13:13:33 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

t_tab	*itoa_hex_pf(t_tab *a, unsigned long long int num)
{
	zero_val_pf(a);
	if (num != 0)
		hex_check_fl_pf(a);
	a->len_num = numlen_sig_pf(num, 16);
	if (num == 0 && a->obel_x[8] == 0)
	{
		hex_null_pf(a);
		return (0);
	}
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		hex_num_zero_pf(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		hex_left_al_pf(a, num);
		return (a);
	}
	other_hex_pf(a, num);
	return (a);
}
