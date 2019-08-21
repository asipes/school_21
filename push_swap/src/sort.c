/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:59 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:24:26 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin_sort(t_push *ds)
{
	ds->balance = ds->size_a;
	ds->mid = ds->size_a / 2;
	ds->temp = ds->a_beg->prev;
	ds->stop = ds->size_a;
	ds->i = 0;
	while (ds->i < ds->stop)
	{
		if (ds->a_beg->ord <= ds->mid)
			PB;
		else
			RA;
		ds->i++;
	}
	if (ds->a_beg->ord <= ds->mid)
		PB;
	sort_stack_b(ds);
}

void	sort_stack_b(t_push *ds)
{
	ds->last = ds->mid;
	ds->mid = (ds->last - ds->next) / 2;
	ds->mid += ds->next;
	ds->temp_num = ds->size_b;
	ds->i = 0;
	in_sort_stack_b(ds);
	if (ds->size_b > 0)
	{
		ds->fl++;
		sort_stack_b(ds);
	}
	sort_stack_a(ds);
}

void	in_sort_stack_b(t_push *ds)
{
	while (ds->i < ds->temp_num)
	{
		if (ds->b_beg->ord > ds->mid)
		{
			ds->b_beg->flag = ds->fl;
			PA;
		}
		else
		{
			if (ds->b_beg->ord == ds->next)
			{
				PA;
				RA;
				ds->next++;
				ds->balance--;
			}
			else
			{
				RB;
			}
		}
		ds->i++;
	}
}

void	sort_stack_a(t_push *ds)
{
	if (ds->a_beg->flag > 0)
	{
		ds->fl_ch = ds->a_beg->flag;
		while (ds->a_beg->flag == ds->fl_ch)
		{
			if (ds->a_beg->ord == ds->next)
			{
				RA;
				ds->balance--;
				ds->next++;
			}
			else
				PB;
		}
	}
	if (ds->size_b > 0)
	{
		w_mid(ds);
		sort_stack_b(ds);
	}
}

void	sort_second(t_push *ds)
{
	ds->mid = (ds->size_a - ds->next) / 2;
	ds->mid += ds->next;
	ds->i = 0;
	while (ds->a_beg->ord != 1)
	{
		if (ds->a_beg->ord <= ds->mid)
			PB;
		else
		{
			RA;
			ds->i++;
		}
	}
	while (ds->a_beg->prev->ord != (ds->next - 1))
	{
		if (ds->b_beg->ord == ds->next)
			RRA;
		else
			RRR;
	}
	sort_stack_b(ds);
}
