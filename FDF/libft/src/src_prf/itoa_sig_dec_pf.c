/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_sig_dec_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:38:06 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/19 18:22:54 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab	*itoa_sig_dec_pf(t_tab *a, long long int num)
{
	zero_val_pf(a);
	check_sig_pf(a, num);
	if (num == 0 && a->obel_x[8] == 0)
	{
		num_zero_pf(a);
		return (a);
	}
	if (num < 0)
		num *= -1;
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
