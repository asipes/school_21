/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_int_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:26:20 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:12:56 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab					*ret_int_pf(t_tab *a, long long int i)
{
	if (a->obel_x[10] < 4)
	{
		i = non_uns_int_pf(a, i);
		itoa_sig_dec_pf(a, i);
	}
	else
	{
		if (a->obel_x[10] == 5)
			a->obel_x[9] = 2;
		i = this_uns_int_pf(a, i);
		if (a->obel_x[10] == 4 || a->obel_x[10] == 5)
			itoa_oct_pf(a, i);
		if (a->obel_x[10] == 6 || a->obel_x[10] == 23)
			itoa_uns_dec_pf(a, i);
		if (a->obel_x[10] == 7 || a->obel_x[10] == 8)
			itoa_hex_pf(a, i);
	}
	return (a);
}
