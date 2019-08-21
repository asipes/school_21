/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ts_p3_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:06:43 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:20:22 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*read_ts_p3_pf(t_tab *a)
{
	while (a->temp[0] == 'z')
	{
		a->obel_x[9] = 7;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	while (a->temp[0] == 't')
	{
		a->obel_x[9] = 8;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_ts_p4_pf(a));
	return (a);
}
