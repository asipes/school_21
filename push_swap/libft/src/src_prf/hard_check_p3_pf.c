/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_check_p3_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 19:12:09 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 19:16:09 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*hard_check_p3_pf(t_tab *a)
{
	while (a->temp[0] == '0')
	{
		if (a->obel_x[5] < 0)
			a->obel_x[5] = 0;
		ft_strcpy(a->temp, &(a->temp[1]));
		if (a->temp[0] == '$')
			return (no_valid_pf(a));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (hard_check_p1_pf(a));
	return (a);
}
