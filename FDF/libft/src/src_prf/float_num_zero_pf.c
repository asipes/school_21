/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_num_zero_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:05:32 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:23:09 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	float_num_zero_pf(t_tab *a)
{
	a->zero = a->obel_x[6] - (a->len_num + a->sig);
	if (a->zero < 0)
		a->zero = 0;
	a->len = a->sig + a->zero;
	a->mass = ft_strnew(a->len);
	if (a->sig == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop = a->sig + a->zero;
	put_zero_pf(a);
	write(1, a->mass, a->len);
	write(1, a->arr, a->len_num);
	a->abs_len += (a->len + a->len_num);
	free(a->arr);
	free(a->mass);
}
