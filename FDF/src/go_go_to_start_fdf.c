/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_go_to_start_fdf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:27:15 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/01 20:23:47 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		go_go_to_start_fdf(t_fdfstr *a)
{
	a->mod_col_h = 255 << 8;
	a->mod_color = 255 << 16;
	a->size_win_x = 1200;
	a->size_win_y = 800;
	a->s_x = a->size_win_x / 2;
	a->s_y = a->size_win_y / 2;
	a->mod_step = 1;
	a->touch_3 = 0;
	a->touch_4 = 20;
	a->pi = 3.14159265358979323846;
	a->betta = a->pi / 180 * 25;
	a->gamma = a->pi / 180 * 15;
	a->cetta = a->pi / 180 * 10;
	a->alfa = a->pi / 180 * 59.5;
	a->mod_hight = 1.0;
	a->mod_see = 1;
	a->mod_size = ((a->size_win_x - a->s_x) / a->c_stl) >
			((a->size_win_y - a->s_y) / a->c_str) ? (a->size_win_y - a->s_y) /
			a->c_str : (a->size_win_x - a->s_x) / a->c_stl;
	a->mod_size = a->mod_size > 0 ? a->mod_size : 1;
}

void		go_go_calk_now_fdf(t_fdfstr *a)
{
	a->c_a = 0;
	a->min_z = a->arr[a->c_a][2] * a->mod_hight * a->mod_size;
	a->max_z = a->arr[a->c_a][2] * a->mod_hight * a->mod_size;
}

void		calk_map_fdf(t_fdfstr *a)
{
	a->c_a = 0;
	while (a->c_a < a->c_par)
	{
		optimizate_line_fdf(a);
		gevi_me_line_fdf(a);
		a->c_a++;
	}
	mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->im2_ptr, 0, 0);
	mlx_pixel_put(a->mlx_ptr, a->win_ptr, a->arr[a->c_a - 1][4],
			a->arr[a->c_a - 1][5], a->b_col_end);
	info_window_fdf(a);
}

int			ch_fdf(t_fdfstr *a, int i)
{
	a->gg = i * a->mod_hight * a->mod_size - a->min_z;
	a->jj = a->max_z - a->min_z;
	a->dd = (double)a->gg / a->jj;
	ch2_fdf(a);
	a->b_col_go += (a->mod_color & 0xFF0000) +
			(r_fdf(a->b_col_rst * a->dd) << 16);
	a->b_col_go += (a->mod_color & 0xFF00) +
			(r_fdf(a->b_col_bst * a->dd) << 8);
	a->b_col_go += (a->mod_color & 0xFF) +
			r_fdf(a->b_col_gst * a->dd);
	return (a->b_col_go);
}

void		ch2_fdf(t_fdfstr *a)
{
	if (((a->mod_color & 0xFF0000) - (a->mod_col_h & 0xFF0000)) > 0)
		a->b_col_rst = -((a->mod_color >> 16) - (a->mod_col_h >> 16));
	else
		a->b_col_rst = (a->mod_col_h >> 16) - (a->mod_color >> 16);
	if (((a->mod_color & 0xFF00) - (a->mod_col_h & 0xFF00)) > 0)
		a->b_col_bst = -(((a->mod_color >> 8) & 0xFF) -
				((a->mod_col_h >> 8) & 0xFF));
	else
		a->b_col_bst = (((a->mod_col_h >> 8) & 0xFF) -
				((a->mod_color >> 8) & 0xFF));
	if (((a->mod_color & 0xFF) - (a->mod_col_h & 0xFF)) > 0)
		a->b_col_gst = -((a->mod_color & 0xFF) - (a->mod_col_h & 0xFF));
	else
		a->b_col_gst = (a->mod_col_h & 0xFF) - (a->mod_color & 0xFF);
	a->b_col_go = 0;
}
