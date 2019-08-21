/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_null_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:14:39 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:22:24 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	hex_null_pf(t_tab *a)
{
	a->space = a->obel_x[6];
	if (a->space < 0)
		a->space = 0;
	a->mass = ft_strnew(a->space);
	a->abs_len += a->space;
	a->stop = a->space;
	put_space_pf(a);
	write(1, a->mass, a->space);
	free(a->mass);
}
