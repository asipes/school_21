/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duck_star_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:42:46 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 08:53:01 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*duck_star_pf(t_tab *a)
{
	a->int_temp = -1;
	ft_strcpy(a->temp, &(a->temp[1]));
	if (ft_isdigit(a->temp[0]))
	{
		a->count_b = 0;
		while (ft_isdigit(a->temp[a->count_b]))
			a->count_b++;
		if (a->temp[a->count_b] == '$')
		{
			a->int_temp = ft_atoi(a->temp);
			while (ft_isdigit(a->temp[0]))
				ft_strcpy(a->temp, &(a->temp[1]));
			ft_strcpy(a->temp, &(a->temp[1]));
			if (a->int_temp == 0)
				return (a);
			a->obel_x[1] = a->int_temp;
			a = read_star_pf(a);
			return (a);
		}
	}
	a->obel_x[1] = a->parametr;
	a = read_star_pf(a);
	a->parametr++;
	return (a);
}
