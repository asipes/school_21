/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_null_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:17:03 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 17:18:00 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	oct_null_pf(t_tab *a)
{
	if (a->obel_x[6] < 1 && a->obel_x[3] == 1 && a->obel_x[8] == 0)
		a->obel_x[6] = 1;
	a->space = a->obel_x[6] - a->sig;
	if (a->space < 0)
		a->space = 0;
	a->len = a->space + a->sig;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->obel_x[5] == 1 && a->sig == 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
		a->sig = 0;
	}
	a->stop = (a->space + 1) - a->sig;
	put_space_pf(a);
	if (a->sig == 1)
		a->mass[a->count_m] = a->sym;
	if (a->obel_x[3] == 1 && a->obel_x[8] == 0)
		a->mass[a->len - 1] = '0';
	write(1, a->mass, a->len);
	free(a->mass);
}
