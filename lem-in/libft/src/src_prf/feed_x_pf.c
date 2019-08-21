/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_x_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:02:37 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:39:19 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*feed_x_pf(t_tab *a)
{
	if (a->obel_x[0] == 1 &&
			!(a->temp = ft_strsub(a->form, 1, a->count_a - 1)))
		return (memory_error_pf(a));
	if (a->obel_x[0] < 1)
	{
		if (a->obel_x[0] &&
				!(a->temp = ft_strsub(a->form, 1, a->count_a - 1)))
			return (memory_error_pf(a));
		if (!(a->obel_x[0]) && !(a->temp = ft_strsub(a->form, 0, a->count_a)))
			return (memory_error_pf(a));
		write(1, a->temp, ft_strlen(a->temp));
		a->abs_len += ft_strlen(a->temp);
		free(a->temp);
	}
	a->form = ft_strcpy(a->form, &(a->form[a->count_a]));
	if (a->obel_x[0] == 1)
		a = check_valid_pf(a);
	a->count_a = 0;
	return (a);
}

t_tab	*fing_my_param_pf(t_tab *a, va_list cap)
{
	if (a->obel_x[10] < 9 || a->obel_x[10] > 16)
	{
		a->count_b = 1 + a->parametr_f + a->parametr_d;
		while (a->count_b < a->parametr)
		{
			a->int_temp = va_arg(cap, int);
			a->count_b++;
		}
		a->parametr_i = a->parametr - a->parametr_d - a->parametr_f;
	}
	if (a->obel_x[10] > 8 && a->obel_x[10] < 17 && a->obel_x[9] == 3)
	{
		a->count_b = 1 + a->parametr_i + a->parametr_f;
		while (a->count_b < a->parametr)
		{
			a->p_double = va_arg(cap, long double);
			a->count_b++;
		}
		a->parametr_d = a->parametr - a->parametr_i - a->parametr_f;
	}
	return (a);
}

void	flag_zero_pf(t_tab *a, unsigned long long int num)
{
	a->len_num = numlen_sig_pf(num, 10);
	a->space = a->obel_x[6] - (a->len_num + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->space + a->len_num;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->sym == '-' || a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop = a->sig + a->space;
	put_zero_pf(a);
	a->stop += (a->len_num - 1);
	put_num_pf(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}

void	float_left_al_pf(t_tab *a)
{
	a->space = a->obel_x[6] - (a->len_num + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->space;
	a->mass = ft_strnew(a->len);
	if (a->sig == 1)
	{
		write(1, &(a->sym), 1);
		a->abs_len++;
	}
	a->stop = a->sig + a->space;
	put_space_pf(a);
	write(1, a->arr, a->len_num);
	write(1, a->mass, a->len);
	a->abs_len += (a->len + a->len_num);
	free(a->arr);
	free(a->mass);
}

void	float_num_zero_pf(t_tab *a)
{
	a->zero = a->obel_x[6] - (a->len_num + a->sig);
	if (a->zero < 0)
		a->zero = 0;
	a->len = a->sig + a->zero;
	a->mass = ft_strnew(a->len);
	if (a->sig == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop = a->sig + a->zero;
	put_zero_pf(a);
	write(1, a->mass, a->len);
	write(1, a->arr, a->len_num);
	a->abs_len += (a->len + a->len_num);
	free(a->arr);
	free(a->mass);
}
