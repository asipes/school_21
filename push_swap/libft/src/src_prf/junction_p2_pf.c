/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junction_p2_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:34:14 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 18:00:26 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
