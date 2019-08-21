/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junction_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:33:06 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:21:56 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
