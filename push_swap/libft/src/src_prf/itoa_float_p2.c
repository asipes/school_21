/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_float_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:39:47 by asipes            #+#    #+#             */
/*   Updated: 2019/05/11 11:08:11 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

void				float_step5_pf(t_tab *a, long double num)
{
	a->arr[a->count_m] = '.';
	a->count_m++;
	if (num > (a->first / 2))
		while (a->obel_x[8])
		{
			a->obel_x[8]--;
			a->arr[a->count_m] = '0';
			a->count_m++;
		}
	else
	{
		while (a->obel_x[8])
		{
			a->tmp_a *= 10;
			a->int_max = (long long int)a->tmp_a;
			a->tmp_a = a->tmp_a - a->int_max;
			a->arr[a->count_m] = (a->int_max % 10) + '0';
			a->count_m++;
			a->obel_x[8]--;
		}
		float_step6_pf(a);
	}
}
