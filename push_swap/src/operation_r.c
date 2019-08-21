/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:30 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:17:30 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push *ds)
{
	if (ds->size_a > 1)
		ds->a_beg = ds->a_beg->next;
}

void	rb(t_push *ds)
{
	if (ds->size_b > 1)
		ds->b_beg = ds->b_beg->next;
}

void	rr(t_push *ds)
{
	if (ds->size_a > 1 && ds->size_b > 1)
	{
		ra(ds);
		rb(ds);
	}
}
