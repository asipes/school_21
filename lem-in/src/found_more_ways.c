/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_more_ways.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:05:04 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/08/08 13:54:38 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*combine_ways1(t_lem_in *a, int i, int j)
{
	int		*arr;
	int		l;

	arr = (int *)malloc(sizeof(int) * (i + 1));
	l = a->cb + 1;
	while (j < i)
	{
		if (j <= a->cc)
			arr[j] = a->w_run->ways[a->ca]->way[j];
		else
		{
			arr[j] = a->w_run->ways[a->w_run->n_way - 1]->way[l];
			l++;
		}
		j++;
	}
	return (arr);
}

int			combine_ways2(t_lem_in *a)
{
	while (a->w_run->ways[a->w_run->n_way - 1]->way[a->cb] ==
			a->w_run->ways[a->ca]->way[a->cc])
	{
		a->cb--;
		a->cc++;
	}
	a->cb++;
	a->cc--;
	return (a->cb + a->w_run->ways[a->ca]->size - a->cc);
}

void		combine_ways(t_lem_in *a, int i, int j)
{
	int		*arr;
	int		*brr;

	i = a->cc + (a->w_run->ways[a->w_run->n_way - 1]->size - a->cb) + 1;
	arr = combine_ways1(a, i, j);
	j = combine_ways2(a);
	brr = (int *)malloc(sizeof(int) * (j + 1));
	ft_memcpy(brr, a->w_run->ways[a->w_run->n_way - 1]->way, sizeof(int) *
			(a->cb + 1));
	ft_memcpy(&(brr[a->cb]), &(a->w_run->ways[a->ca]->way[a->cc]),
			sizeof(int) * (a->w_run->ways[a->ca]->size - a->cc + 1));
	free(a->w_run->ways[a->w_run->n_way - 1]->way);
	free(a->w_run->ways[a->ca]->way);
	a->w_run->ways[a->w_run->n_way - 1]->way = brr;
	a->w_run->ways[a->w_run->n_way - 1]->size = j;
	a->w_run->ways[a->ca]->way = arr;
	a->w_run->ways[a->ca]->size = i - 1;
	include_way(a, 0, 0, 0);
}

void		include_way(t_lem_in *a, int i, int j, int k)
{
	include_way_m(a);
	while (i < a->w_run->n_way - 1)
	{
		j = a->w_run->ways[a->w_run->n_way - 1]->size - 1;
		while (j > 0)
		{
			k = 1;
			while (k < a->w_run->ways[i]->size)
			{
				if (a->w_run->ways[a->w_run->n_way - 1]->way[j] ==
						a->w_run->ways[i]->way[k] && j > a->cb)
				{
					a->ca = i;
					a->cb = j;
					a->cc = k;
					k = a->w_run->ways[i]->size;
				}
				k++;
			}
			j--;
		}
		i++;
	}
	if (a->ca != -1)
		combine_ways(a, 0, 0);
}

void		include_way_m(t_lem_in *a)
{
	a->ca = -1;
	a->cb = -1;
	a->cc = -1;
}
