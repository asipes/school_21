/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_sig_dec_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:38:06 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/07/21 13:38:46 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		num *= -1;
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

t_tab	*itoa_uns_dec_pf(t_tab *a, unsigned long long int num)
{
	a->obel_x[4] = 0;
	zero_val_pf(a);
	if (num == 0 && a->obel_x[8] == 0)
	{
		num_zero_pf(a);
		return (a);
	}
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

t_tab	*junction_p2_pf(va_list cap, t_tab *a)
{
	if (a->obel_x[10] == 19)
	{
		a->p_string = va_arg(cap, char *);
		a = ret_string_pf(a, a->p_string);
	}
	else if (a->obel_x[10] == 21)
	{
		a->p_point = (unsigned long long int)va_arg(cap, void *);
		a->obel_x[9] = 2;
		a->obel_x[10] = 7;
		a->obel_x[3] = 1;
		ret_point_pf(a);
	}
	else if (a->obel_x[10] == 23)
	{
		a->p_int = va_arg(cap, long long int);
		a->obel_x[9] = 2;
		ret_int_pf(a, a->p_int);
	}
	return (a);
}

t_tab	*junction_pf(va_list cap, t_tab *a)
{
	if (a->obel_x[10] < 9)
	{
		a->p_int = va_arg(cap, long long int);
		ret_int_pf(a, a->p_int);
	}
	else if (a->obel_x[10] < 17 && a->obel_x[9] != 3)
	{
		a->p_float = va_arg(cap, double);
		ret_float_pf(a, a->p_float);
	}
	else if (a->obel_x[10] < 17 && a->obel_x[9] == 3)
	{
		a->p_double = va_arg(cap, long double);
		ret_float_pf(a, a->p_double);
	}
	else if (a->obel_x[10] == 17 || a->obel_x[10] == 18)
	{
		a->p_char = (char)va_arg(cap, int);
		a = ret_char_pf(a, a->p_char);
	}
	else
		return (junction_p2_pf(cap, a));
	return (a);
}

void	left_al_pf(t_tab *a, unsigned long long int num)
{
	a->len_num = numlen_sig_pf(num, 10);
	left_al_var_pf(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->sym == '-' || a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop = a->sig + a->zero;
	put_zero_pf(a);
	a->stop += (a->len_num - 1);
	put_num_pf(a, num);
	a->stop = (a->count_m);
	a->stop += a->space;
	put_space_pf(a);
	write(1, a->mass, a->len);
	free(a->mass);
}
