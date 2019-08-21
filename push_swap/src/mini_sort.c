/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:10 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:18:51 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_push *ds)
{
	if (ds->size_a == 2)
		duo_sort(ds);
	else if (ds->size_a == 3)
		trio_sort(ds);
	else if (ds->size_a == 4)
		quadro_sort(ds);
	else
		penta_sort(ds);
}

void	duo_sort(t_push *ds)
{
	if (ds->a_beg->ord != 1)
		SA;
}

void	trio_sort(t_push *ds)
{
	if (FIRST < SECOND)
	{
		if (FIRST < THIRD && SECOND > THIRD)
		{
			SA;
			RA;
		}
		else if (FIRST > THIRD)
		{
			RRA;
		}
	}
	else if (FIRST > SECOND)
	{
		if (FIRST < THIRD)
			SA;
		else if (FIRST > THIRD && SECOND < THIRD)
			RA;
		else if (FIRST > THIRD && SECOND > THIRD)
		{
			SA;
			RRA;
		}
	}
}

void	quadro_sort(t_push *ds)
{
	search_max(ds);
	if (ds->i > 1)
	{
		while (ds->a_beg->ord != 1)
			RA;
	}
	else
	{
		while (ds->a_beg->ord != 1)
		{
			RRA;
		}
	}
	PB;
	trio_sort(ds);
	PA;
}

void	penta_sort(t_push *ds)
{
	ds->i = 2;
	while (ds->i > 0)
	{
		if (ds->a_beg->ord < 3)
		{
			PB;
			ds->i--;
		}
		else
			RA;
	}
	trio_sort(ds);
	if (ds->b_beg->ord == 1)
		SB;
	PA;
	PA;
}
