/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_oct_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 12:25:49 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/19 10:26:00 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab	*itoa_oct_pf(t_tab *a, unsigned long long int num)
{
	zero_val_pf(a);
	a->len_num = numlen_sig_pf(num, 8);
	if (a->obel_x[3] == 1 && num != 0)
	{
		a->sym = '0';
		a->sig = 1;
	}
	if (num == 0 && a->obel_x[8] == 0)
	{
		oct_null_pf(a);
		return (a);
	}
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		oct_num_zero_pf(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		oct_left_al_pf(a, num);
		return (a);
	}
	other_oct_pf(a, num);
	return (a);
}
