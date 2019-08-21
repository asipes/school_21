/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_me_param_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:59:07 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 08:34:39 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
