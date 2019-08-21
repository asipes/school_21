/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:10:56 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:10:58 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubbles(t_push *ds)
{
	ds->i = 0;
	while (ds->i < ds->size_e)
	{
		ds->j = 1;
		while (ds->j < ds->size_e)
		{
			if (ds->extra_stack[ds->j - 1] > ds->extra_stack[ds->j])
			{
				ds->temp_num = ds->extra_stack[ds->j - 1];
				ds->extra_stack[ds->j - 1] = ds->extra_stack[ds->j];
				ds->extra_stack[ds->j] = ds->temp_num;
			}
			ds->j++;
		}
		ds->i++;
	}
	check_equally(ds);
}

void	add_extra_stack(t_push *ds)
{
	if (!(ds->extra_stack = (int *)malloc(sizeof(int) * ds->size_e)))
	{
		ft_printf("Error\n");
		exit(0);
	}
	ds->i = 0;
	ds->run = ds->a_beg;
	while (ds->i < ds->size_e)
	{
		ds->extra_stack[ds->i] = ds->run->val;
		RUN_NEXT;
		ds->i++;
	}
	bubbles(ds);
}
