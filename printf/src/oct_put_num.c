/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_put_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 22:38:15 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/04/29 21:33:56 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	oct_put_num(t_tab *a, unsigned long long int num)
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
