/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_value_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:27:34 by asipes            #+#    #+#             */
/*   Updated: 2019/08/08 16:32:27 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_matrix(t_lem_in *a, int i)
{
	a->run = a->c_beg;
	while (i < a->size_sc)
	{
		if (a->run->flag == 6)
		{
			if (a->sv == 0)
				a->sv = 1;
			put_connect(a, 0, 0);
		}
		RUN;
		i++;
	}
}

void	put_connect(t_lem_in *a, int left, int right)
{
	a->run_r = a->r_beg;
	if (a->sv == 0)
	{
		ft_printf("No connect!\n");
		lem_exit(0, a);
	}
	while (!(ft_strequ(a->run->name_fc, a->run_r->name)))
		RUN_R;
	left = a->run_r->ord;
	a->run_r = a->r_beg;
	while (!(ft_strequ(a->run->name_sc, a->run_r->name)))
		RUN_R;
	right = a->run_r->ord;
	a->a_conn[left][right] = 1;
	a->a_conn[right][left] = 1;
	a->s_rooms = a->size_r;
}
