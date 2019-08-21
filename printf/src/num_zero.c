/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:46:25 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/04/29 21:33:40 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	num_zero_null(t_tab *a)
{
	a->space = a->obel_x[6] - a->sig;
	if (a->space < 0)
		a->space = 0;
	a->len = a->space + a->sig;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->space;
	put_space(a);
	if (a->obel_x[4] >= 1)
		a->mass[a->count_m] = a->sym;
	write(1, a->mass, a->len);
	free(a->mass);
}

void	num_zero_left(t_tab *a)
{
	a->space = a->obel_x[6] - a->sig;
	if (a->space < 0)
		a->space = 0;
	a->len = a->space + a->sig;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop = a->len;
	put_space(a);
	write(1, a->mass, a->len);
	free(a->mass);
}

void	num_zero(t_tab *a)
{
	if (a->obel_x[5] == 1)
	{
		num_zero_left(a);
		return ;
	}
	num_zero_null(a);
}
