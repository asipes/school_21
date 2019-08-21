/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apdate_deikstra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:24:42 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/08/08 13:54:21 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	apt_finding_the_way(t_lem_in *a, int i)
{
	i = 0;
	while (i < a->size_r)
	{
		a->rooms_cov[i] = 0;
		a->weight[i] = 200000;
		i++;
	}
	a->weight[0] = 0;
	apt_dijkstras_algorithm(a);
}

int		apt_check_repeate(t_lem_in *a, int i, int j)
{
	while (i < a->cb)
	{
		if (j == a->rooms_cov[i])
			return (0);
		i++;
	}
	return (1);
}

void	we_have_some_one_problem_plus(t_lem_in *a)
{
	a->rooms[a->w_run->ways[a->ce]->way[a->cc]]->numb = a->ce;
	a->cc--;
	a->rooms_cov[a->cb] = a->ca;
	a->cb++;
	a->ca = a->w_run->ways[a->ce]->way[a->cc];
}

void	we_have_some_one_problem(t_lem_in *a, int kast)
{
	we_have_some_one_problem_plus(a);
	while (a->cc > 0)
	{
		a->rooms[a->w_run->ways[a->ce]->way[a->cc]]->numb = a->ce;
		a->rooms[a->w_run->ways[a->ce]->way[a->cc]]->p_room =
			a->rooms[a->w_run->ways[a->ce]->way[a->cc + 1]];
		a->cf = 1;
		while (a->cf < a->cb)
		{
			if (a->rooms_cov[a->cf] == a->w_run->ways[a->ce]->way[a->cc])
			{
				ft_memcpy(&a->rooms_cov[a->cf], &a->rooms_cov[a->cf + 1],
						sizeof(int) * (a->cb - a->cf - 1));
				a->cb--;
			}
			a->cf++;
		}
		kast += 0;
		a->weight[a->w_run->ways[a->ce]->way[a->cc]] =
				a->p_weight[a->w_run->ways[a->ce]->way[a->cc]];
		a->cc--;
	}
}

void	apt_next_room_for_deksta_plus(t_lem_in *a, int min)
{
	a->cc = 0;
	while (a->cc < a->size_r)
	{
		if (a->ca != a->cc && a->weight[a->cc] <= min &&
				apt_check_repeate(a, 0, a->cc))
		{
			a->ca = a->cc;
			min = a->weight[a->cc];
		}
		a->cc++;
	}
	if (min == 100000)
		a->ca = a->size_r - 1;
	a->ce = 0;
}
