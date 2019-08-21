/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:47 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:17:48 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_order(t_push *ds)
{
	ds->i = 0;
	ds->run = ds->a_beg;
	while (ds->i < ds->size_a)
	{
		ds->j = 0;
		while (ds->j < ds->size_a)
		{
			if (ds->run->val == ds->extra_stack[ds->j])
				ds->run->ord = ds->j + 1;
			ds->j++;
		}
		ds->run = ds->run->next;
		ds->i++;
	}
}

void	w_mid(t_push *ds)
{
	ds->run = ds->b_beg;
	ds->i = 0;
	ds->mid = 0;
	while (ds->i < ds->size_b)
	{
		if (ds->run->ord > ds->mid)
			ds->mid = ds->run->ord;
		RUN_NEXT;
		ds->i++;
	}
}

void	short_cut(t_push *ds)
{
	ds->i = 0;
	ds->j = 0;
	ds->run = ds->b_beg;
	while (ds->run->ord != ds->next)
	{
		RUN_NEXT;
		ds->i++;
	}
	ds->run = ds->b_beg;
	while (ds->run->ord != ds->next)
	{
		RUN_PREV;
		ds->j++;
	}
	if (ds->i < ds->j)
		RB;
	else
		RRB;
}

void	search_max(t_push *ds)
{
	ds->i = 0;
	ds->run = ds->a_beg;
	while (ds->run->ord != 1)
	{
		ds->i++;
		RUN_NEXT;
	}
}
