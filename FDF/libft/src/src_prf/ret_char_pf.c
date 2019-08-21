/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_char_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:29:19 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 16:55:40 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab	*ret_char_pf(t_tab *a, char c)
{
	if (a->obel_x[6] < 2)
	{
		write(1, &c, 1);
		a->abs_len++;
		return (a);
	}
	zero_val_pf(a);
	if (a->obel_x[5] == 0)
	{
		zero_char_pf(a, c);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		char_left_al_pf(a, c);
		return (a);
	}
	other_char_pf(a, c);
	return (a);
}
