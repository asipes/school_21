/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_2_3_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:39:30 by asipes            #+#    #+#             */
/*   Updated: 2019/08/08 13:54:40 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	relevants(t_lem_in *a, int len, int i)
{
	a->array_ways = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		a->array_ways[i] = a->w_run->ways[i]->size;
		i++;
	}
	a->c_min_step = sort_array(a, 1, 0, len);
	a->min_step = a->array_ways[0];
	a->max_step = a->array_ways[len - 1];
	forecast(a, len, 1);
	free(a->array_ways);
}

void	forecast(t_lem_in *a, int len, int i)
{
	int step;
	int pat;

	pat = 1;
	step = 0;
	while (i < len && pat < a->s_ants)
	{
		pat = pat + (a->array_ways[i] - a->array_ways[i - 1]) * i + 1;
		i++;
	}
	if (pat >= a->s_ants)
	{
		step = a->array_ways[i - 1];
	}
	else if (i == len)
	{
		step = (a->s_ants - pat) / len + a->array_ways[len - 1];
		if ((a->s_ants - pat) % len)
			step++;
	}
	if (a->prew_steps >= step)
		a->go_next = 1;
	else
		a->go_next = 0;
	a->prew_steps = step;
}

int		relevants_len(t_lem_in *a, int i)
{
	a->pat = 1;
	while (i < a->len && a->pat <= a->p_ants)
	{
		a->pat = a->pat + (a->array_ways[i] - a->array_ways[i - 1]) * i + 1;
		i++;
	}
	if (i == 0)
		i++;
	return (i);
}

void	step_by_step(t_lem_in *a, int stop, int i, int j)
{
	while (stop)
	{
		i = 0;
		while (i < a->s_ants && a->turn == a->step_ants[i][0])
		{
			j = 0;
			while (a->step_ants[i][2]
					!= a->w_run->ways[a->step_ants[i][1]]->way[j])
				j++;
			a->step_ants[i][0]++;
			if (a->w_run->ways[a->step_ants[i][1]]->way[j] != a->size_r - 1)
			{
				a->step_ants[i][2] =
						a->w_run->ways[a->step_ants[i][1]]->way[j + 1];
				if (a->step_ants[i][2] == a->size_r - 1)
					stop--;
				ft_printf("L%i-", i);
				ft_printf("[%s] ", a->rooms[a->step_ants[i][2]]->name);
			}
			i++;
		}
		ft_putchar('\n');
		a->turn++;
	}
}
