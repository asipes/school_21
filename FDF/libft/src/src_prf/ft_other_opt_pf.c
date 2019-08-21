/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_opt_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:34:52 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/19 10:24:49 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_other_opt_pf(t_tab *a, long long int num)
{
	a->space = a->obel_x[6] - a->len;
	a->zero = a->obel_x[8] - a->len;
	if (a->zero > 0)
		a->space -= a->zero;
	if (a->sym == '-' || a->obel_x[4] == 2)
		a->space--;
	if (a->space > 0)
		while (a->space--)
		{
			write(1, " ", 1);
			a->abs_len++;
		}
	if (a->sym == '-' || a->obel_x[4] == 2)
	{
		write(1, &(a->sym), 1);
		a->abs_len++;
	}
	if (a->zero > 0)
		while (a->zero--)
		{
			write(1, "0", 1);
			a->abs_len++;
		}
	ft_other_opt_p_pf(a, num);
}
