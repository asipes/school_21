/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_put_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:41:28 by asipes            #+#    #+#             */
/*   Updated: 2019/05/14 13:13:31 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	hex_put_num_pf(t_tab *a, unsigned long long int num)
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
