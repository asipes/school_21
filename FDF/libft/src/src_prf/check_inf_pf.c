/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inf_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:10:15 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:23:33 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	check_inf_pf(t_tab *a, double num)
{
	if (num > 0)
	{
		if (a->obel_x[4] == 1)
		{
			if (a->obel_x[7])
				ret_string_pf(a, " inf");
			else
				ret_string_pf(a, " INF");
		}
		else if (a->obel_x[4] == 2)
		{
			if (a->obel_x[7])
				ret_string_pf(a, "+inf");
			else
				ret_string_pf(a, "+INF");
		}
		else if (a->obel_x[7])
			ret_string_pf(a, "inf");
		else
			ret_string_pf(a, "INF");
	}
	else if (a->obel_x[7])
		ret_string_pf(a, "-inf");
	else
		ret_string_pf(a, "-INF");
}
