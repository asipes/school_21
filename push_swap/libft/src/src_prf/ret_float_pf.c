/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_float_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:28:49 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:11:08 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab	*ret_float_pf(t_tab *a, long double num)
{
	if (check_nan_pf(a, num))
		return (a);
	zero_val_pf(a);
	a->sym = 0;
	if (a->obel_x[4] == 1)
		a->sym = ' ';
	if (a->obel_x[4] == 2)
		a->sym = '+';
	if (num < 0)
	{
		a->sym = '-';
		num *= -1;
	}
	if (a->sym == '-' || a->sym == '+' || a->sym == ' ')
		a->sig = 1;
	if (a->obel_x[8] < 0)
		a->obel_x[8] = 6;
	itoa_float_pf(a, num);
	if (a->error == 1)
		return (memory_error_pf(a));
	put_itoa_float_pf(a);
	return (a);
}
