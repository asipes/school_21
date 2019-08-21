/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_sig_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:38:06 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/14 13:41:03 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	put_num_pf(t_tab *a, unsigned long long int num)
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

void	put_zero_pf(t_tab *a)
{
	while (a->count_m < a->stop)
	{
		a->mass[a->count_m] = '0';
		a->count_m++;
	}
}

void	put_space_pf(t_tab *a)
{
	while (a->count_m < a->stop)
	{
		a->mass[a->count_m] = ' ';
		a->count_m++;
	}
}

void	other_put_pf(t_tab *a, unsigned long long int num)
{
	a->len_num = numlen_sig_pf(num, 10);
	left_al_var_pf(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->space;
	put_space_pf(a);
	if (a->sym == '-' || a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop += (a->sig + a->zero);
	put_zero_pf(a);
	a->stop += (a->len_num - 1);
	put_num_pf(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}

t_tab	*itoa_sig_dec_pf(t_tab *a, long long int num)
{
	zero_val_pf(a);
	check_sig_pf(a, num);
	if (num == 0 && a->obel_x[8] == 0)
	{
		num_zero_pf(a);
		return (a);
	}
	if (num < 0)
		num = pr_max_val_pf(a, num);
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		flag_zero_pf(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		left_al_pf(a, num);
		return (0);
	}
	other_put_pf(a, num);
	return (a);
}
