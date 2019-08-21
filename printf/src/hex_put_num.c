/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_put_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:41:28 by asipes            #+#    #+#             */
/*   Updated: 2019/04/29 21:16:49 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hex_put_num(t_tab *a, unsigned long long int num)
{
	a->sym = a->obel_x[10] == 7 ? 'a' : 'A';
	while (num > 15)
	{
		a->mass[a->stop] = (num % 16) + (num % 16 > 9 ? a->sym - 10 : '0');
		a->stop--;
		a->count_m++;
		num /= 16;
	}
	if (num < 16)
	{
		a->mass[a->stop] = (num % 16) + (num % 16 > 9 ? a->sym - 10 : '0');
		a->count_m++;
	}
}
