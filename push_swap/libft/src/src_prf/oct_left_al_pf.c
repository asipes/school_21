/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_left_al_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:18:48 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:21:27 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	oct_left_al_pf(t_tab *a, unsigned long long int num)
{
	a->zero = a->obel_x[8] - (a->len_num + a->sig);
	if (a->zero < 0)
		a->zero = 0;
	a->space = a->obel_x[6] - (a->len_num + a->zero + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->space + a->len_num + a->sig + a->zero;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->zero;
	put_zero_pf(a);
	if (a->sig == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop += (a->len_num + a->sig) - 1;
	oct_put_num_pf(a, num);
	a->stop = a->count_m + a->space;
	put_space_pf(a);
	write(1, a->mass, a->len);
	num = num + 1;
	free(a->mass);
}
