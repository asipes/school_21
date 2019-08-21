/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_char_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:29:19 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/04/29 21:33:11 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	zero_char(t_tab *a, char c)
{
	a->zero = a->obel_x[6];
	a->mass = ft_strnew(a->zero);
	a->abs_len += a->zero;
	a->stop = a->zero - 1;
	put_zero(a);
	a->mass[a->count_m] = c;
	write(1, a->mass, a->zero);
	free(a->mass);
}

void	char_left_al(t_tab *a, char c)
{
	a->space = a->obel_x[6];
	a->mass = ft_strnew(a->space);
	a->abs_len += a->space;
	a->mass[a->count_m] = c;
	a->count_m++;
	a->stop = a->space;
	put_space(a);
	write(1, a->mass, a->space);
	free(a->mass);
}

void	other_char(t_tab *a, char c)
{
	a->space = a->obel_x[6];
	a->mass = ft_strnew(a->space);
	a->abs_len += a->space;
	a->stop = a->space - 1;
	put_space(a);
	a->mass[a->count_m] = c;
	write(1, a->mass, a->space);
	free(a->mass);
}

t_tab	*ret_char_pf(t_tab *a, char c)
{
	if (a->obel_x[6] < 2)
	{
		write(1, &c, 1);
		a->abs_len++;
		return (a);
	}
	zero_val(a);
	if (a->obel_x[5] == 0)
	{
		zero_char(a, c);
	}
	if (a->obel_x[5] == 1)
	{
		char_left_al(a, c);
		return (a);
	}
	other_char(a, c);
	return (a);
}
