/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nan_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:10:56 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:23:29 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		check_nan_pf(t_tab *a, double num)
{
	a->obel_x[7] = a->obel_x[10] % 2;
	if (num != num)
	{
		a->obel_x[8] = -1;
		if (a->obel_x[5] == 0)
			a->obel_x[5] = -1;
		if (a->obel_x[7])
			ret_string_pf(a, "nan");
		else
			ret_string_pf(a, "NAN");
		return (1);
	}
	if (num == (num * 10) && num)
	{
		a->obel_x[8] = -1;
		if (a->obel_x[5] == 0)
			a->obel_x[5] = -1;
		check_inf_pf(a, num);
		return (1);
	}
	return (0);
}
