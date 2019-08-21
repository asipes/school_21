/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_star_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:53:32 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 18:58:50 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*read_star_pf(t_tab *a)
{
	va_list	cap;

	va_copy(cap, a->ap);
	a->count_b = 0;
	while (a->count_b < a->obel_x[1])
	{
		a->int_temp = va_arg(cap, int);
		a->count_b++;
	}
	va_end(cap);
	a->obel_x[1] = -1;
	a->count_b = 0;
	return (a);
}
