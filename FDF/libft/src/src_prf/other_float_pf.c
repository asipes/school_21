/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_float_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:03:00 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:21:10 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
