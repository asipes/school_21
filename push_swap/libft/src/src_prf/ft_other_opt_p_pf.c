/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_opt_p_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:24:52 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 08:25:11 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_other_opt_p_pf(t_tab *a, long long int num)
{
	if (num == 0 && a->obel_x[8] == 0)
	{
		a->len = 0;
		if (a->obel_x[4] == 1 && a->sym == '+' && a->obel_x[6] > 0)
		{
			write(1, " ", 1);
			a->abs_len++;
		}
	}
	if (num == 0 && a->obel_x[8] != 0)
		write(1, "0", 1);
}
