/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_left_al_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:08:27 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:23:36 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	char_left_al_pf(t_tab *a, char c)
{
	a->space = a->obel_x[6];
	a->mass = ft_strnew(a->space);
	a->abs_len += a->space;
	a->mass[a->count_m] = c;
	a->count_m++;
	a->stop = a->space;
	put_space_pf(a);
	write(1, a->mass, a->space);
	free(a->mass);
}
