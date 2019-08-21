/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_put_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 22:38:15 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/14 13:13:39 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	oct_put_num_pf(t_tab *a, unsigned long long int num)
{
	while (num > 7)
	{
		a->mass[a->stop] = (num % 8) + '0';
		a->stop--;
		a->count_m++;
		num /= 8;
	}
	if (num < 8)
	{
		a->mass[a->stop] = (num % 8) + '0';
		a->count_m++;
	}
}
