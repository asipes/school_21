/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apdate_deikstra_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:50:27 by asipes            #+#    #+#             */
/*   Updated: 2019/08/08 13:54:18 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	apt_next_room_for_deksta(t_lem_in *a, int min, int kast)
{
	apt_next_room_for_deksta_plus(a, min);
	while (a->ca < a->size_r - 1 && a->ce < a->w_run->n_way - 1)
	{
		a->cc = 1;
		while (a->cc < a->w_run->ways[a->ce]->size)
		{
			if (a->w_run->ways[a->ce]->way[a->cc] == a->ca)
			{
				if (a->w_run->ways[a->ce]->way[a->cc + 1] !=
					a->rooms[a->w_run->ways[a->ce]->way[a->cc]]->p_room->ord)
				{
					if (a->a_conn[kast][a->ca] > 0)
						a->rooms[a->ca]->e_room = a->rooms[kast];
					we_have_some_one_problem(a, kast);
				}
				return ;
			}
			else
				a->cc++;
		}
		a->ce++;
	}
}

void	apt_dijkstras_algorithm(t_lem_in *a)
{
	a->ca = 0;
	a->cb = 0;
	while (a->ca < a->size_r - 1)
	{
		a->cd = 0;
		while (a->cd < a->size_r)
		{
			if (a->a_conn[a->ca][a->cd] > 0 && a->weight[a->cd] >
				(a->weight[a->ca] + 1) && apt_check_repeate(a, 0, a->cd))
			{
				a->weight[a->cd] = a->weight[a->ca] + 1;
				a->rooms[a->cd]->p_room = a->rooms[a->ca];
				if (a->rooms[a->cd]->numb == a->rooms[a->ca]->numb)
					a->rooms[a->cd]->e_room = a->rooms[a->ca];
			}
			a->cd++;
		}
		a->rooms_cov[a->cb] = a->ca;
		a->cb++;
		apt_next_room_for_deksta(a, 100000, a->ca);
	}
	apt_short_cat(a, 0, 0);
}

void	apt_short_cat(t_lem_in *a, int i, int j)
{
	a->rooms[a->size_r - 1]->check = 0;
	if (!(a->rooms[a->size_r - 1]->p_room))
	{
		a->go_next = 0;
		return ;
	}
	else
	{
		a->r_beg->p_room = NULL;
		a->run_r = a->rooms[a->size_r - 1];
		j = apt_short_cat_1(a, i, a->run_r->numb);
		if (j == -5)
			return ;
		i = a->size_short + 1;
		apt_short_cat_2(a, i, j);
	}
	a->go_next = 1;
}

int		apt_short_cat_1(t_lem_in *a, int i, int j)
{
	while (a->run_r)
	{
		if ((a->size_r > 500 && i > (a->size_r / 4)) || i > a->size_r)
		{
			a->go_next = 0;
			return (-5);
		}
		i++;
		a->run_r->check = 1;
		if (j == a->run_r->numb && a->run_r->e_room)
		{
			j = a->run_r->numb;
			a->run_r = a->run_r->e_room;
		}
		else
		{
			j = a->run_r->numb;
			a->run_r = a->run_r->p_room;
		}
	}
	a->size_short = i - 1;
	a->short_cat = (int *)malloc(sizeof(int) * (i));
	a->run_r = a->rooms[a->size_r - 1];
	return (a->run_r->numb);
}

void	apt_short_cat_2(t_lem_in *a, int i, int j)
{
	while (a->run_r)
	{
		i--;
		a->short_cat[i] = a->run_r->ord;
		if (j == a->run_r->numb && a->run_r->e_room)
		{
			j = a->run_r->numb;
			a->run_r = a->run_r->e_room;
		}
		else
		{
			j = a->run_r->numb;
			a->run_r = a->run_r->p_room;
		}
	}
	i = 0;
	while (i < a->size_r - 1)
	{
		a->rooms[i]->numb = -1;
		a->rooms[i]->e_room = NULL;
		a->rooms[i]->p_room = NULL;
		i++;
	}
}
