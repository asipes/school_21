/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_the_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:11:15 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/08/08 13:54:32 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	finding_the_way(t_lem_in *a, int i)
{
	a->rooms_cov = (int *)malloc(sizeof(int) * a->size_r);
	a->weight = (int *)malloc(sizeof(int) * a->size_r);
	a->p_weight = (int *)malloc(sizeof(int) * a->size_r);
	while (i < a->size_r)
	{
		a->rooms_cov[i] = 0;
		a->weight[i] = 200000;
		a->p_weight[i] = 200000;
		i++;
	}
	a->weight[0] = 0;
	dijkstras_algorithm(a);
}

int		check_repeate(t_lem_in *a, int i)
{
	while (i < a->cb)
	{
		if (a->cc == a->rooms_cov[i])
			return (0);
		i++;
	}
	return (1);
}

void	next_room_for_deksta(t_lem_in *a, int min)
{
	a->cc = 0;
	while (a->cc < a->size_r)
	{
		if (a->weight[a->cc] <= min && check_repeate(a, 0))
		{
			a->ca = a->cc;
			min = a->weight[a->cc];
		}
		a->cc++;
	}
}

void	dijkstras_algorithm(t_lem_in *a)
{
	a->ca = 0;
	a->cb = 0;
	while (a->ca < a->size_r - 1)
	{
		a->cd = 0;
		while (a->cd < a->size_r)
		{
			if (a->a_conn[a->ca][a->cd] > 0 && a->weight[a->cd] >
					(a->weight[a->ca] + 1))
			{
				a->weight[a->cd] = a->weight[a->ca] + 1;
				a->rooms[a->cd]->p_room = a->rooms[a->ca];
			}
			a->cd++;
		}
		a->rooms_cov[a->cb] = a->ca;
		a->cb++;
		next_room_for_deksta(a, 100000);
	}
	a->short_cat = (int *)malloc(sizeof(int) * a->weight[a->size_r - 1] + 1);
	short_cat(a);
}

void	short_cat(t_lem_in *a)
{
	int	i;

	i = a->weight[a->size_r - 1];
	if (!(a->rooms[a->size_r - 1]->p_room))
		lem_exit(ft_printf("No anithing way\n"), a);
	a->run_r = a->rooms[a->size_r - 1];
	while (i)
	{
		a->short_cat[i] = a->run_r->ord;
		i--;
		a->run_r = a->run_r->p_room;
	}
}
