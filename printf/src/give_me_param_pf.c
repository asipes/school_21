/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_me_param_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:59:07 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/11 11:37:44 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab		*junction_p2_pf(va_list cap, t_tab *a)
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
		if (a->p_point == 0 && a->obel_x[8] < 3)
			a->obel_x[8] = -1;
		if (a->p_point == 0)
			return (ret_string_pf(a, "0x0"));
		ret_int_pf(a, a->p_point);
	}
	else if (a->obel_x[10] == 23)
	{
		a->p_int = va_arg(cap, long long int);
		a->obel_x[9] = 2;
		ret_int_pf(a, a->p_int);
	}
	return (a);
}

t_tab		*junction_pf(va_list cap, t_tab *a)
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

t_tab		*fing_my_param_pf(t_tab *a, va_list cap)
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

t_tab		*give_me_param_pf(t_tab *a)
{
	va_list	cap;

	va_copy(cap, a->ap);
	a = fing_my_param_pf(a, cap);
	if (a->obel_x[10] > 8 && a->obel_x[10] < 17 && a->obel_x[9] != 3)
	{
		a->count_b = 1 + a->parametr_i + a->parametr_d;
		while (a->count_b < a->parametr)
		{
			a->p_float = va_arg(cap, double);
			a->count_b++;
		}
		a->parametr_f = a->parametr - a->parametr_i - a->parametr_d;
	}
	a->parametr++;
	a->p_float = 0;
	a->p_double = 0;
	a->int_temp = 0;
	a = junction_pf(cap, a);
	va_end(cap);
	return (a);
}
