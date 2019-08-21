/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_itoa_float_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:28:58 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/19 11:08:05 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab	*put_itoa_float_pf(t_tab *a)
{
	if (a->obel_x[5] == 0)
	{
		float_num_zero_pf(a);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		float_left_al_pf(a);
		return (a);
	}
	other_float_pf(a);
	return (a);
}
