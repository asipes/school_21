/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_hex_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 22:41:35 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/19 10:25:46 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab	*itoa_hex_pf(t_tab *a, unsigned long long int num)
{
	zero_val_pf(a);
	if (num != 0)
		hex_check_fl_pf(a);
	a->len_num = numlen_sig_pf(num, 16);
	if (num == 0 && a->obel_x[8] == 0)
	{
		hex_null_pf(a);
		return (0);
	}
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		hex_num_zero_pf(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		hex_left_al_pf(a, num);
		return (a);
	}
	other_hex_pf(a, num);
	return (a);
}
