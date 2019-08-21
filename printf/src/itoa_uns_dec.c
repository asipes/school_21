/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_uns_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:22:55 by asipes            #+#    #+#             */
/*   Updated: 2019/04/29 21:23:03 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	*itoa_uns_dec(t_tab *a, unsigned long long int num)
{
	a->obel_x[4] = 0;
	zero_val(a);
	if (num == 0 && a->obel_x[8] == 0)
	{
		num_zero(a);
		return (a);
	}
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		flag_zero(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		left_al(a, num);
		return (0);
	}
	other_put(a, num);
	return (a);
}
