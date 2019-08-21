/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:01 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 16:17:05 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*check_valid_pf(t_tab *a)
{
	while (a->temp)
	{
		if (!(a->temp[0]) && *a->form == '%')
			return (percent_type_pf(a));
		if (!(a->temp[0]))
		{
			free(a->temp);
			return (a);
		}
		a->count_a = 0;
		while (a->temp[0] != a->tf[a->count_a] && a->tf[a->count_a]
				&& a->temp[0])
			a->count_a++;
		if (a->tf[a->count_a] && a->temp[0])
			a = hard_check_pf(a);
		else
			return (no_valid_pf(a));
		if (a->obel_x[2] == 7)
			return (a);
	}
	return (a);
}
