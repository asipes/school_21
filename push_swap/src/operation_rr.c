/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:35 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:17:36 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push *ds)
{
	if (ds->size_a > 1)
		ds->a_beg = ds->a_beg->prev;
}

void	rrb(t_push *ds)
{
	if (ds->size_b > 1)
		ds->b_beg = ds->b_beg->prev;
}

void	rrr(t_push *ds)
{
	if (ds->size_a > 1 && ds->size_b > 1)
	{
		rra(ds);
		rrb(ds);
	}
}
