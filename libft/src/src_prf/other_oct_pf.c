/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_oct_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:16:20 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:38:26 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_tab	*percent_type_pf(t_tab *a)
{
	free(a->temp);
	a->count_a = 1;
	while (a->form[a->count_a] && a->form[a->count_a] != '%')
		a->count_a++;
	if ((a->form[a->count_a] &&
			!(a->temp = ft_strsub(a->form, 0, a->count_a - 1))))
		return (memory_error_pf(a));
	if ((!(a->form[a->count_a]) &&
			!(a->temp = ft_strsub(a->form, 0, a->count_a))))
		return (memory_error_pf(a));
	a->form = ft_strcpy(a->form, &(a->form[a->count_a]));
	return (no_valid_pf(a));
}

t_tab	*put_itoa_float_pf(t_tab *a)
{
	if (a->obel_x[5] == 0)
	{
		float_num_zero_pf(a);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		float_left_al_pf(a);
		return (a);
	}
	other_float_pf(a);
	return (a);
}

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
