/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_uns_dec_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:22:55 by asipes            #+#    #+#             */
/*   Updated: 2019/05/19 10:56:50 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab	*itoa_uns_dec_pf(t_tab *a, unsigned long long int num)
{
	a->obel_x[4] = 0;
	zero_val_pf(a);
	if (num == 0 && a->obel_x[8] == 0)
	{
		num_zero_pf(a);
		return (a);
	}
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		flag_zero_pf(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		left_al_pf(a, num);
		return (0);
	}
	other_put_pf(a, num);
	return (a);
}
