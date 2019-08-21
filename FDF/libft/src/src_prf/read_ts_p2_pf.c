/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ts_p2_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:06:05 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:20:26 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*read_ts_p2_pf(t_tab *a)
{
	while (a->temp[0] == 'h')
	{
		if (a->temp[1] == 'h')
		{
			if (a->obel_x[9] < 1 || a->obel_x[9] == 3)
				a->obel_x[9] = 5;
			ft_strcpy(a->temp, &(a->temp[1]));
		}
		else if (a->obel_x[9] < 1 || a->obel_x[9] == 3 || a->obel_x[9] == 5)
			a->obel_x[9] = 4;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	while (a->temp[0] == 'j')
	{
		a->obel_x[9] = 6;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_ts_p3_pf(a));
	return (a);
}
