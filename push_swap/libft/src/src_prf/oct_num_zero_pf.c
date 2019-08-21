/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_num_zero_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:18:12 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:21:21 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	oct_num_zero_pf(t_tab *a, unsigned long long int num)
{
	a->zero = a->obel_x[6] - (a->len_num + a->sig);
	if (a->zero < 0)
		a->zero = 0;
	a->len = a->zero + a->sig + a->len_num;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->zero;
	put_zero_pf(a);
	if (a->obel_x[3] == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop += (a->len_num + a->sig) - 1;
	oct_put_num_pf(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}
