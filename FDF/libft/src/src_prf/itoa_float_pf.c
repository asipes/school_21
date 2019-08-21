/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_float_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:19:54 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:25:33 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				itoa_float_pf(t_tab *a, long double num)
{
	float_step1_pf(a, num);
	float_step2_pf(a);
	float_step3_pf(a, num);
	if (a->arr[0] == '0')
	{
		if ((int)a->tmp_b)
			ft_strcpy(a->arr, &a->arr[1]);
		a->len_num--;
	}
	a->len = 0;
	a->full = 0;
	a->zero = 0;
	a->stop = 0;
	a->space = 0;
	a->count_m = 0;
}
