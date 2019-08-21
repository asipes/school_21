/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_left_al_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:04:48 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 14:19:55 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
