/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_step6_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:11:18 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:22:50 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				float_step6_pf(t_tab *a)
{
	if ((a->tmp_a > 0.5) || (a->tmp_a >= 0.5 && a->int_max % 2))
	{
		a->int_max++;
		a->count_m--;
		if (a->int_max < 10)
			a->arr[a->count_m] = a->int_max + '0';
		while (a->int_max == 10)
		{
			a->arr[a->count_m] = '0';
			a->count_m--;
			if (a->arr[a->count_m] == '.')
				a->count_m--;
			a->int_max = a->arr[a->count_m] - '0';
			a->int_max++;
			if (a->int_max > 0 && a->int_max < 9)
				a->arr[a->count_m] = a->int_max + '0';
		}
	}
}
