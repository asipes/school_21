/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_mach_par_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:01:37 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 18:49:32 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*how_mach_par_pf(t_tab *a)
{
	a->error = 0;
	faster_faster_pf(a);
	while (a->form[a->count_a])
	{
		a->count_a = 1;
		a = clean_my_array_pf(a);
		if (a->form[0] == '%')
		{
			if (a->form[1] == '%')
				a->count_a = 2;
			else
				(a->obel_x[0] = 1);
		}
		else
			a->obel_x[0] = 0;
		while (a->form[a->count_a] != '%' && a->form[a->count_a])
			a->count_a++;
		a = feed_x_pf(a);
		if (a->error)
			return (a);
		a->count_a = 0;
	}
	return (a);
}
