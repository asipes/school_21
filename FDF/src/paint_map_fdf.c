/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:13:18 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/01 01:03:54 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		camera_mod_1_fdf(t_fdfstr *a)
{
	calk_parametrs_fdf(a);
	a->arr[a->c_a][4] += a->s_x;
	a->arr[a->c_a][5] += a->s_y;
}

void		camera_mod_2_fdf(t_fdfstr *a)
{
	a->z1 = a->arr[a->c_a][2] * a->mod_hight * a->mod_size;
	if (a->z1 > a->max_z)
		a->max_z = a->z1;
	if (a->z1 < a->min_z)
		a->min_z = a->z1;
	a->arr[a->c_a][4] = (a->arr[a->c_a][0] - a->c_stl / 2) * a->mod_size
			+ a->s_x;
	a->arr[a->c_a][5] = (a->arr[a->c_a][1] - a->c_str / 2) * a->mod_size
			+ a->s_y;
}

void		camera_mod_3_fdf(t_fdfstr *a)
{
	a->z1 = a->arr[a->c_a][2] * a->mod_hight * a->mod_size;
	if (a->z1 > a->max_z)
		a->max_z = a->z1;
	if (a->z1 < a->min_z)
		a->min_z = a->z1;
	a->arr[a->c_a][4] = a->arr[a->c_a][0] * a->mod_size *
			((float)1 / 5 * a->mod_hight * a->arr[a->c_a][2] + 1) + a->s_x / 2;
	a->arr[a->c_a][5] = a->arr[a->c_a][1] * a->mod_size *
			((float)1 / 5 * a->mod_hight * a->arr[a->c_a][2] + 1) + a->s_y / 2;
}

void		camera_mod_4_fdf(t_fdfstr *a)
{
	calk_parametrs_fdf(a);
	a->x1 = a->arr[a->c_a][4];
	a->arr[a->c_a][4] = (a->x1 - a->arr[a->c_a][5]) *
			cos(a->alfa);
	a->arr[a->c_a][5] = (a->arr[a->c_a][4] + a->arr[a->c_a][5]) *
			sin(a->alfa) - a->arr[a->c_a][6];
	a->arr[a->c_a][4] += a->s_x;
	a->arr[a->c_a][5] += a->s_y;
}

int			paint_map_fdf(t_fdfstr *a)
{
	go_go_calk_now_fdf(a);
	while (a->c_a < a->c_par && a->mod_see == 1)
	{
		camera_mod_1_fdf(a);
		a->c_a++;
	}
	while (a->c_a < a->c_par && a->mod_see == 2)
	{
		camera_mod_2_fdf(a);
		a->c_a++;
	}
	while (a->c_a < a->c_par && a->mod_see == 3)
	{
		camera_mod_3_fdf(a);
		a->c_a++;
	}
	while (a->c_a < a->c_par && a->mod_see == 4)
	{
		camera_mod_4_fdf(a);
		a->c_a++;
	}
	calk_map_fdf(a);
	return (0);
}
