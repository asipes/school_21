/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_check_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:48:18 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 19:19:51 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*hard_check_pf(t_tab *a)
{
	while (a->temp[0] == '.')
	{
		ft_strcpy(a->temp, &(a->temp[1]));
		a->int_temp = 0;
		if (ft_isdigit(a->temp[0]))
		{
			a->int_temp = ft_atoi(&(a->temp[0]));
			while (ft_isdigit(a->temp[0]))
				ft_strcpy(a->temp, &(a->temp[1]));
		}
		else if (a->temp[0] == '*')
			a = duck_star_pf(a);
		a->obel_x[8] = a->int_temp >= 0 ? a->int_temp : -1;
	}
	return (hard_check_p3_pf(a));
}
