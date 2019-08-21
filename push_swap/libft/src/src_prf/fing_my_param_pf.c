/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fing_my_param_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:31:26 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:23:14 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
