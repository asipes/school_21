/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_step1_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:06:00 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:23:06 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				float_step1_pf(t_tab *a, long double num)
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
