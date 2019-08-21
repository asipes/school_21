/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_step1_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:06:00 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:39:13 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	float_step1_pf(t_tab *a, long double num)
{
	a->first = -1;
	a->first /= 2;
	a->len = 1;
	a->space = 0;
	a->stop = 1;
	a->tmp_a = num;
	if (a->tmp_a < 10)
		a->tmp_b = a->tmp_a;
	while (a->tmp_a >= 10)
	{
		if (a->tmp_a > a->first)
			a->space++;
		else if (a->stop)
		{
			a->stop = 0;
			a->tmp_b = a->tmp_a;
		}
		a->len++;
		a->tmp_a /= 10;
	}
}

void	float_step2_pf(t_tab *a)
{
	a->len_num = a->len + a->obel_x[8] + 1;
	if (a->obel_x[8])
		a->len_num++;
	if (!(a->arr = ft_strnew(a->len_num)))
	{
		memory_error_pf(a);
		return ;
	}
	a->count_m = 1;
	a->tmp_a = a->tmp_b;
	a->int_max = (long long int)a->tmp_a;
	a->tmp_a = a->tmp_a - a->int_max;
	a->zero = a->len - a->space;
	a->arr[0] = '0';
	while (a->int_max)
	{
		a->arr[a->zero] = (a->int_max % 10) + '0';
		a->int_max /= 10;
		a->zero--;
		a->count_m++;
	}
}

void	float_step3_pf(t_tab *a, long double num)
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

void	float_step4_pf(t_tab *a)
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

void	float_step5_pf(t_tab *a, long double num)
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
