/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:52:12 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/02 18:17:08 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		clean_list_fdf(t_fdfstr *a, t_fdfread *newl)
{
	newl = a->bs_list;
	while (a->bs_list)
	{
		a->bs_list = newl->next;
		if (newl->str)
			free(newl->str);
		free(newl);
		newl = a->bs_list;
	}
	a->c_a = 0;
	a->bs_list = NULL;
	test_anton_fdf(a);
	return (0);
}

void	optimizate_line_fdf(t_fdfstr *a)
{
	if (a->arr[a->c_a][0] > 0 && ((a->arr[a->c_a - 1][4] < 0 &&
			a->arr[a->c_a][4] < 0) || (a->arr[a->c_a - 1][4] > a->size_win_x
			&& a->arr[a->c_a][4] > a->size_win_x) || (a->arr[a->c_a - 1][5] < 0
			&& a->arr[a->c_a][5] < 0) || (a->arr[a->c_a - 1][5] > a->size_win_y
			&& a->arr[a->c_a][5] > a->size_win_y)))
		a->arr[a->c_a - 1][5] = a->arr[a->c_a][5];
	if (a->arr[a->c_a][1] > 0 && ((a->arr[a->c_a - a->c_stl][4] < 0 &&
			a->arr[a->c_a][4] < 0) || (a->arr[a->c_a - a->c_stl][4] >
			a->size_win_x && a->arr[a->c_a][4] > a->size_win_x) ||
			(a->arr[a->c_a - a->c_stl][5] < 0 && a->arr[a->c_a][5] < 0) ||
			(a->arr[a->c_a - a->c_stl][5] > a->size_win_y && a->arr[a->c_a][5]
			> a->size_win_y)))
	{
		a->arr[a->c_a - a->c_stl][4] = a->arr[a->c_a][4];
		a->arr[a->c_a - a->c_stl][5] = a->arr[a->c_a][5];
	}
}
