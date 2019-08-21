/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_check_p2_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:56:52 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 08:57:26 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*hard_check_p2_pf(t_tab *a)
{
	while (a->temp[0] == ' ' || a->temp[0] == '+' || a->temp[0] == '-' ||
			a->temp[0] == '#')
	{
		if (a->temp[0] == '#')
			a->obel_x[3] = 1;
		if (a->temp[0] == ' ' && a->obel_x[4] < 1)
			a->obel_x[4] = 1;
		if (a->temp[0] == '+')
			a->obel_x[4] = 2;
		if (a->temp[0] == '-')
			a->obel_x[5] = 1;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_type_and_spec_pf(a));
	return (a);
}
