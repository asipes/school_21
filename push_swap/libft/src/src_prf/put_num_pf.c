/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:24:38 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:20:45 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	put_num_pf(t_tab *a, unsigned long long int num)
{
	while (num > 9)
	{
		if (a->full == 1)
		{
			a->mass[a->stop] = (num % 10) + '1';
			a->stop--;
			a->count_m++;
			num /= 10;
		}
		a->mass[a->stop] = (num % 10) + '0';
		a->stop--;
		a->count_m++;
		num /= 10;
	}
	if (num < 10)
	{
		a->mass[a->stop] = (num % 10) + '0';
		a->count_m++;
	}
}
