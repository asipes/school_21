/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:20 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:17:20 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_push *ds)
{
	if (ds->size_a > 0)
	{
		ds->run = ds->a_beg;
		ds->a_beg->next->prev = ds->a_beg->prev;
		ds->a_beg->prev->next = ds->a_beg->next;
		ds->a_beg = ds->a_beg->next;
		ds->size_a--;
		if (ds->size_b == 0)
		{
			ds->b_beg = ds->run;
			ds->b_beg->next = ds->b_beg;
			ds->b_beg->prev = ds->b_beg;
			ds->size_b++;
		}
		else
			pb_p(ds);
		if (ds->size_a == 0)
			ds->a_beg = NULL;
	}
}

void	pb_p(t_push *ds)
{
	ds->run->next = ds->b_beg;
	ds->run->prev = ds->b_beg->prev;
	ds->b_beg->prev->next = ds->run;
	ds->b_beg->prev = ds->run;
	ds->b_beg = ds->run;
	ds->size_b++;
}

void	pa(t_push *ds)
{
	if (ds->size_b > 0)
	{
		ds->run = ds->b_beg;
		ds->b_beg->next->prev = ds->b_beg->prev;
		ds->b_beg->prev->next = ds->b_beg->next;
		ds->b_beg = ds->b_beg->next;
		ds->size_b--;
		if (ds->size_a == 0)
		{
			ds->a_beg = ds->run;
			ds->a_beg->next = ds->a_beg;
			ds->a_beg->prev = ds->a_beg;
			ds->size_a++;
		}
		else
			pa_p(ds);
		if (ds->size_b == 0)
			ds->b_beg = NULL;
	}
}

void	pa_p(t_push *ds)
{
	ds->run->next = ds->a_beg;
	ds->run->prev = ds->a_beg->prev;
	ds->a_beg->prev->next = ds->run;
	ds->a_beg->prev = ds->run;
	ds->a_beg = ds->run;
	ds->size_a++;
}
