/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:26:25 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 09:04:25 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*initialize_pf(t_tab *a)
{
	a->abs_len = 0;
	a->count_a = 0;
	a->parametr = 1;
	a->parametr_i = 0;
	a->parametr_f = 0;
	a->parametr_d = 0;
	a = array_of_param_pf(a);
	if (!(a->obel_x = (int *)malloc(sizeof(int) * 11)))
		return (memory_error_pf(a));
	a = how_mach_par_pf(a);
	if (a->error)
		return (a);
	return (a);
}
