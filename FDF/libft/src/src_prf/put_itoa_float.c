/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_itoa_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:28:58 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/14 13:13:40 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

void	float_left_al_pf(t_tab *a)
{
	a->space = a->obel_x[6] - (a->len_num + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->space;
	a->mass = ft_strnew(a->len);
	if (a->sig == 1)
	{
		write(1, &(a->sym), 1);
		a->abs_len++;
	}
	a->stop = a->sig + a->space;
	put_space_pf(a);
	write(1, a->arr, a->len_num);
	write(1, a->mass, a->len);
	a->abs_len += (a->len + a->len_num);
	free(a->arr);
	free(a->mass);
}

void	other_float_pf(t_tab *a)
{
	a->space = a->obel_x[6] - (a->len_num + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->space;
	a->mass = ft_strnew(a->len);
	a->stop = a->space;
	put_space_pf(a);
	if (a->sig == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	write(1, a->mass, a->len);
	write(1, a->arr, a->len_num);
	a->abs_len += (a->len + a->len_num);
	free(a->arr);
	free(a->mass);
}

t_tab	*put_itoa_float_pf(t_tab *a)
{
	if (a->obel_x[5] == 0)
	{
		float_num_zero_pf(a);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		float_left_al_pf(a);
		return (a);
	}
	other_float_pf(a);
	return (a);
}
