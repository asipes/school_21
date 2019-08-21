/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:46:25 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/14 13:41:13 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	num_zero_null_pf(t_tab *a)
{
	a->space = a->obel_x[6] - a->sig;
	if (a->space < 0)
		a->space = 0;
	a->len = a->space + a->sig;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->space;
	put_space_pf(a);
	if (a->obel_x[4] >= 1)
		a->mass[a->count_m] = a->sym;
	write(1, a->mass, a->len);
	free(a->mass);
}

void	num_zero_left_pf(t_tab *a)
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
	put_space_pf(a);
	write(1, a->mass, a->len);
	free(a->mass);
}

void	num_zero_pf(t_tab *a)
{
	if (a->obel_x[5] == 1)
	{
		num_zero_left_pf(a);
		return ;
	}
	num_zero_null_pf(a);
}
