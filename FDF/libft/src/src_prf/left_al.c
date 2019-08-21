/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_al.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:31:40 by asipes            #+#    #+#             */
/*   Updated: 2019/05/14 13:13:38 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	left_al_var_pf(t_tab *a)
{
	a->zero = a->obel_x[8] - a->len_num;
	if (a->zero < 0)
		a->zero = 0;
	a->space = a->obel_x[6] - (a->len_num + a->zero + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->zero + a->len_num + a->space;
}

void	left_al_pf(t_tab *a, unsigned long long int num)
{
	a->len_num = numlen_sig_pf(num, 10);
	left_al_var_pf(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->sym == '-' || a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop = a->sig + a->zero;
	put_zero_pf(a);
	a->stop += (a->len_num - 1);
	put_num_pf(a, num);
	a->stop = (a->count_m);
	a->stop += a->space;
	put_space_pf(a);
	write(1, a->mass, a->len);
	free(a->mass);
}
