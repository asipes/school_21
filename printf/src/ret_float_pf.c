/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_float_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:28:49 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/04/29 21:47:51 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_inf_pf(t_tab *a, double num)
{
	if (num > 0)
	{
		if (a->obel_x[4] == 1)
		{
			if (a->obel_x[7])
				ret_string_pf(a, " inf");
			else
				ret_string_pf(a, " INF");
		}
		else if (a->obel_x[4] == 2)
		{
			if (a->obel_x[7])
				ret_string_pf(a, "+inf");
			else
				ret_string_pf(a, "+INF");
		}
		else if (a->obel_x[7])
			ret_string_pf(a, "inf");
		else
			ret_string_pf(a, "INF");
	}
	else if (a->obel_x[7])
		ret_string_pf(a, "-inf");
	else
		ret_string_pf(a, "-INF");
}

int		check_nan_pf(t_tab *a, double num)
{
	a->obel_x[7] = a->obel_x[10] % 2;
	if (num != num)
	{
		a->obel_x[8] = -1;
		if (a->obel_x[5] == 0)
			a->obel_x[5] = -1;
		if (a->obel_x[7])
			ret_string_pf(a, "nan");
		else
			ret_string_pf(a, "NAN");
		return (1);
	}
	if (num == (num * 10) && num)
	{
		a->obel_x[8] = -1;
		if (a->obel_x[5] == 0)
			a->obel_x[5] = -1;
		check_inf_pf(a, num);
		return (1);
	}
	return (0);
}

t_tab	*ret_float_pf(t_tab *a, long double num)
{
	if (check_nan_pf(a, num))
		return (a);
	zero_val(a);
	a->sym = 0;
	if (a->obel_x[4] == 1)
		a->sym = ' ';
	if (a->obel_x[4] == 2)
		a->sym = '+';
	if (num < 0)
	{
		a->sym = '-';
		num *= -1;
	}
	if (a->sym == '-' || a->sym == '+' || a->sym == ' ')
		a->sig = 1;
	if (a->obel_x[8] < 0)
		a->obel_x[8] = 6;
	itoa_float_pf(a, num);
	if (a->error == 1)
		return (memory_error_pf(a));
	put_itoa_float(a);
	return (a);
}
