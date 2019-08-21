/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_more_ways_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:53:26 by asipes            #+#    #+#             */
/*   Updated: 2019/08/08 13:54:36 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	found_more_ways_1(t_lem_in *a)
{
	a->w_beg = (t_combo *)malloc(sizeof(t_combo));
	a->w_beg->ways = (t_way **)malloc(sizeof(t_way *));
	a->w_beg->ways[0] = (t_way *)malloc(sizeof(t_way));
	a->w_beg->n_way = 1;
	a->w_beg->prew = NULL;
	a->w_beg->ways[0]->way = a->short_cat;
	a->w_beg->ways[0]->size = a->weight[a->size_r - 1];
	a->w_run = a->w_beg;
	if (a->w_run->ways[0]->size == 1)
		step_solo_way_ants(a, 0);
	a->prew_steps = a->w_beg->ways[0]->size + a->s_ants;
	a->w_run->next = (t_combo *)malloc(sizeof(t_combo));
	a->w_run->next->prew = a->w_run;
	a->w_run = a->w_run->next;
	a->go_next = 1;
}

int		found_more_ways_2(t_lem_in *a, int j)
{
	a->w_run->n_way = a->w_run->prew->n_way + 1;
	a->w_run->ways = (t_way **)malloc(sizeof(t_way *) * a->w_run->n_way);
	j = 0;
	while (j < a->w_run->n_way - 1)
	{
		a->w_run->ways[j] = (t_way *)malloc(sizeof(t_way));
		a->w_run->ways[j]->way = (int *)malloc(sizeof(int) *
			(a->w_run->prew->ways[j]->size + 1));
		ft_memcpy(a->w_run->ways[j]->way, a->w_run->prew->ways[j]->way,
			sizeof(int) * (a->w_run->prew->ways[j]->size + 1));
		a->w_run->ways[j]->size = a->w_run->prew->ways[j]->size;
		j++;
	}
	a->rooms[a->size_r - 1]->p_room = NULL;
	return (j);
}

void	found_more_ways_3(t_lem_in *a, int k, int j)
{
	while (j && k)
	{
		k--;
		a->p_weight[a->w_run->ways[j - 1]->way[k]] =
				a->weight[a->w_run->ways[j - 1]->way[k]];
		a->a_conn[a->w_run->ways[j - 1]->way[k]]
				[a->w_run->ways[j - 1]->way[k + 1]] = -1;
		if (k == 0)
		{
			j--;
			if (j)
				k = a->w_run->ways[j - 1]->size;
		}
	}
	apt_finding_the_way(a, 0);
}

void	found_more_ways_4(t_lem_in *a, int k, int j)
{
	if (a->fp)
		ft_printf(".");
	a->w_run->ways[a->w_run->n_way - 1] = (t_way *)malloc(sizeof(t_way));
	a->w_run->ways[a->w_run->n_way - 1]->way = a->short_cat;
	a->w_run->ways[a->w_run->n_way - 1]->size = a->size_short;
	j = a->w_run->n_way - 1;
	k = a->w_run->ways[j - 1]->size;
	while (j && k)
	{
		k--;
		a->a_conn[a->w_run->ways[j - 1]->way[k]]
				[a->w_run->ways[j - 1]->way[k + 1]] = 1;
		if (k == 0)
		{
			j--;
			if (j)
				k = a->w_run->ways[j - 1]->size;
		}
	}
}

void	found_more_ways(t_lem_in *a, int j, int k)
{
	found_more_ways_1(a);
	while (a->go_next)
	{
		j = found_more_ways_2(a, j);
		k = a->w_run->ways[j - 1]->size;
		found_more_ways_3(a, k, j);
		if (a->go_next == 0)
		{
			a->w_run = a->w_run->prew;
			return ;
		}
		found_more_ways_4(a, k, j);
		include_way(a, 0, 0, 0);
		a->w_run->next = (t_combo *)malloc(sizeof(t_combo));
		a->w_run->next->prew = a->w_run;
		relevants(a, a->w_run->n_way, 0);
		if (a->go_next == 0)
		{
			a->w_run = a->w_run->prew;
			return ;
		}
		a->w_run = a->w_run->next;
		a->w_run->next = NULL;
	}
}
