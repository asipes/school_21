/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:08:53 by asipes            #+#    #+#             */
/*   Updated: 2019/04/29 20:09:46 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_zero(t_tab *a, unsigned long long int num)
{
	a->len_num = numlen_sig_pf(num, 10);
	a->space = a->obel_x[6] - (a->len_num + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->space + a->len_num;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->sym == '-' || a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop = a->sig + a->space;
	put_zero(a);
	a->stop += (a->len_num - 1);
	put_num(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}
