/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_step2_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:07:21 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:23:02 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				float_step2_pf(t_tab *a)
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
