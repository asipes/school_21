/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_step4_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:09:18 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:22:56 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				float_step4_pf(t_tab *a)
{
	a->int_max = a->arr[a->count_m - 1] - '0';
	if ((a->tmp_a > 0.5) || (a->tmp_a >= 0.5 && a->int_max % 2))
	{
		a->int_max++;
		while (a->int_max == 10)
		{
			a->count_m--;
			a->arr[a->count_m] = '0';
			a->int_max = a->arr[a->count_m - 1] - '0';
			a->int_max++;
		}
		a->arr[a->count_m - 1] = '0' + a->int_max;
	}
}
