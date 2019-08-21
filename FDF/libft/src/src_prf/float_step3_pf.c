/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_step3_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:08:10 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:22:59 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				float_step3_pf(t_tab *a, long double num)
{
	while (a->space)
	{
		a->tmp_a *= 10;
		a->int_max = (long long int)a->tmp_a;
		a->tmp_a = a->tmp_a - a->int_max;
		a->arr[a->count_m] = (a->int_max % 10) + '0';
		a->count_m++;
		a->space--;
	}
	if (!a->obel_x[8])
		float_step4_pf(a);
	else
		float_step5_pf(a, num);
}
