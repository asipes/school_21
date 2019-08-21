/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_point_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:22:58 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 18:05:22 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*ret_point_pf(t_tab *a)
{
	if (a->p_point == 0)
	{
		if (a->obel_x[8] == -1)
			a->obel_x[8] = 1;
		if (!(a->po = ft_strnew(a->obel_x[8] + 2)))
			return (memory_error_pf(a));
		a->po[0] = '0';
		a->po[1] = 'x';
		while (a->obel_x[8])
		{
			a->po[a->obel_x[8] + 1] = '0';
			a->obel_x[8]--;
		}
		a->obel_x[8] = -1;
		ret_string_pf(a, a->po);
		free(a->po);
		return (a);
	}
	ret_int_pf(a, a->p_point);
	return (a);
}
