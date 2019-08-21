/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_type_and_spec_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:47:51 by asipes            #+#    #+#             */
/*   Updated: 2019/05/19 10:07:27 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*read_type_and_spec_pf(t_tab *a)
{
	while (a->temp[0] == 'l')
	{
		if (a->temp[1] == 'l')
		{
			a->obel_x[9] = 2;
			ft_strcpy(a->temp, &(a->temp[2]));
		}
		else
		{
			if (a->obel_x[9] != 2)
				a->obel_x[9] = 1;
			ft_strcpy(a->temp, &(a->temp[1]));
		}
	}
	while (a->temp[0] == 'L')
	{
		if (a->obel_x[9] < 1)
			a->obel_x[9] = 3;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_ts_p2_pf(a));
	return (a);
}
