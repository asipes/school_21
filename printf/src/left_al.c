/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_al.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:31:40 by asipes            #+#    #+#             */
/*   Updated: 2019/04/29 21:32:00 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	left_al_var(t_tab *a)
{
	a->zero = a->obel_x[8] - a->len_num;
	if (a->zero < 0)
		a->zero = 0;
	a->space = a->obel_x[6] - (a->len_num + a->zero + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->zero + a->len_num + a->space;
}

void	left_al(t_tab *a, unsigned long long int num)
{
	a->len_num = numlen_sig_pf(num, 10);
	left_al_var(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->sym == '-' || a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop = a->sig + a->zero;
	put_zero(a);
	a->stop += (a->len_num - 1);
	put_num(a, num);
	a->stop = (a->count_m);
	a->stop += a->space;
	put_space(a);
	write(1, a->mass, a->len);
	free(a->mass);
}
