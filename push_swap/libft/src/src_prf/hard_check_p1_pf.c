/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_check_p1_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:54:25 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 19:06:22 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*hard_check_p1_pf(t_tab *a)
{
	if (ft_isdigit(a->temp[0]))
	{
		a->int_temp = ft_atoi(a->temp);
		while (ft_isdigit(a->temp[0]))
			ft_strcpy(a->temp, &(a->temp[1]));
		if (a->temp[0] == '$')
		{
			a->parametr = a->int_temp;
			ft_strcpy(a->temp, &(a->temp[1]));
		}
		else
			a->obel_x[6] = a->int_temp;
	}
	while (a->temp[0] == '*')
	{
		a = duck_star_pf(a);
		a->obel_x[5] = a->int_temp < 0 ? 1 : a->obel_x[5];
		a->obel_x[6] = a->int_temp > 0 ? a->int_temp : -1 * a->int_temp;
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (hard_check_p2_pf(a));
	return (a);
}
