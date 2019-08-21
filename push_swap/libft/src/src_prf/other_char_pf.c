/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_char_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:07:47 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:21:13 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	other_char_pf(t_tab *a, char c)
{
	a->space = a->obel_x[6];
	a->mass = ft_strnew(a->space);
	a->abs_len += a->space;
	a->stop = a->space - 1;
	put_space_pf(a);
	a->mass[a->count_m] = c;
	write(1, a->mass, a->space);
	free(a->mass);
}
