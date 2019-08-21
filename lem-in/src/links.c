/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:54:54 by asipes            #+#    #+#             */
/*   Updated: 2019/08/08 15:33:48 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	initilisation_step_array(t_lem_in *a, int len, int i)
{
	a->p_ants = a->s_ants;
	a->turn = 1;
	a->array_ways = (int *)malloc(sizeof(int) * len);
	a->step_ants = (int **)malloc(sizeof(int *) * a->s_ants);
	a->step_ants[0] = (int *)malloc(sizeof(int) * a->s_ants * 3);
	a->len = len;
	while (i < a->len)
	{
		a->array_ways[i] = a->w_run->ways[i]->size;
		i++;
	}
	a->c_min_step = sort_array(a, 1, 0, a->len);
}

void	step_ants(t_lem_in *a, int len, int i, int j)
{
	int	route;

	initilisation_step_array(a, len, i);
	null_ants_arr(a, (a->s_ants * 3), 0, 1);
	while (i < a->s_ants && a->p_ants > 0)
	{
		j = relevants_len(a, 0);
		len = j;
		route = 0;
		while (j > 0 && i < a->s_ants)
		{
			a->step_ants[i][0] = a->turn;
			a->step_ants[i][1] = route;
			route++;
			i++;
			j--;
		}
		if (a->pat >= a->p_ants)
			a->len--;
		a->p_ants -= len;
		a->turn++;
	}
	sort_array_way(a, 1);
	a->turn = 1;
	vis_or_dont_vis(a, 0, 0);
}

void	vis_or_dont_vis(t_lem_in *a, int i, int j)
{
	if (a->fw)
	{
		while (i < a->w_run->n_way)
		{
			j = 0;
			while (j < a->w_run->ways[i]->size)
			{
				ft_printf("[%s] ", a->rooms[a->w_run->ways[i]->way[j]]->name);
				j++;
			}
			ft_printf("[%s]\n", a->rooms[a->w_run->ways[i]->way[j]]->name);
			i++;
		}
		ft_printf("\n\n");
	}
	if (!a->fv || a->s_rooms > 6530)
		step_by_step(a, a->s_ants, 0, 0);
	else
		visualisation(a);
}

void	step_solo_way_ants(t_lem_in *a, int i)
{
	initilisation_step_array(a, 1, i);
	null_ants_arr(a, (a->s_ants * 3), 0, 1);
	while (i < a->s_ants)
	{
		a->step_ants[i][0] = 1;
		a->step_ants[i][1] = 0;
		a->step_ants[i][2] = 0;
		i++;
	}
	a->turn = 1;
	vis_or_dont_vis(a, 0, 0);
	lem_exit(0, a);
}
