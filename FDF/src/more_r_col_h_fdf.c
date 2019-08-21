/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_r_col_h_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:35:14 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:36 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		more_r_col_h_fdf(t_fdfstr *a)
{
	if (((a->mod_col_h >> 16) + a->mod_step) <= 255)
		a->mod_col_h += a->mod_step << 16;
	else
		a->mod_col_h = (255 << 16) + (a->mod_col_h & 0xFFFF);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_r_col_h_fdf(t_fdfstr *a)
{
	if (((a->mod_col_h >> 16) - a->mod_step) >= 0)
		a->mod_col_h -= a->mod_step << 16;
	else
		a->mod_col_h = (a->mod_col_h & 0xFFFF);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_b_col_h_fdf(t_fdfstr *a)
{
	if (((a->mod_col_h & 0xFF) + a->mod_step) <= 255)
		a->mod_col_h += a->mod_step;
	else
		a->mod_col_h = 255 + (a->mod_col_h & 0xFFFF00);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_b_col_h_fdf(t_fdfstr *a)
{
	if (((a->mod_col_h & 0xFF) - a->mod_step) >= 0)
		a->mod_col_h -= a->mod_step;
	else
		a->mod_col_h = (a->mod_col_h & 0xFFFF00);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
