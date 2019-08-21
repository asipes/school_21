/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_char_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:09:25 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 16:54:20 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	zero_char_pf(t_tab *a, char c)
{
	a->zero = a->obel_x[6];
	a->mass = ft_strnew(a->zero);
	a->abs_len += a->zero;
	a->stop = a->zero - 1;
	put_zero_pf(a);
	a->mass[a->count_m] = c;
	write(1, a->mass, a->zero);
	free(a->mass);
}
