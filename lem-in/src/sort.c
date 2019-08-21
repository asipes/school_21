/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:53:41 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/08/07 16:17:59 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			sort_array(t_lem_in *a, int i, int tmp, int len)
{
	int		j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (a->array_ways[j] > a->array_ways[j + 1])
			{
				tmp = a->array_ways[j];
				a->array_ways[j] = a->array_ways[j + 1];
				a->array_ways[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < len && a->array_ways[i - 1] == a->array_ways[i])
		i++;
	return (i);
}

int			null_ants_arr(t_lem_in *a, int len, int i, int j)
{
	while (i < len)
	{
		a->step_ants[0][i] = 0;
		i++;
	}
	i = 3;
	while (i < len)
	{
		a->step_ants[j] = &a->step_ants[0][i];
		j++;
		i += 3;
	}
	return (0);
}

void		sort_array_way(t_lem_in *a, int i)
{
	int		j;
	t_way	*tmp;

	i = 0;
	while (i < a->w_run->n_way - 1)
	{
		j = 0;
		while (j < a->w_run->n_way - 1 - i)
		{
			if (a->w_run->ways[j]->size > a->w_run->ways[j + 1]->size)
			{
				tmp = a->w_run->ways[j];
				a->w_run->ways[j] = a->w_run->ways[j + 1];
				a->w_run->ways[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
