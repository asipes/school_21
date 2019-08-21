/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centrolize_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:45:36 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 22:51:49 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		centrolize_fdf(t_fdfstr *a)
{
	a->s_x = a->size_win_x / 2;
	a->s_y = a->size_win_y / 2;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		centrol_fdf(t_fdfstr *a)
{
	if (a->mod_see == 1)
	{
		a->betta = a->pi / 180 * 25;
		a->gamma = a->pi / 180 * 15;
		a->cetta = a->pi / 180 * 10;
	}
	if (a->mod_see == 4)
	{
		a->betta = 0;
		a->gamma = 0;
		a->cetta = 0;
	}
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_g_col_h_fdf(t_fdfstr *a)
{
	if ((((a->mod_col_h >> 8) & 0xFF) + a->mod_step) <= 255)
		a->mod_col_h += a->mod_step << 8;
	else
		a->mod_col_h = (255 << 8) + (a->mod_col_h & 0xFF00FF);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_g_col_h_fdf(t_fdfstr *a)
{
	if ((((a->mod_col_h >> 8) & 0xFF) - a->mod_step) >= 0)
		a->mod_col_h -= a->mod_step << 8;
	else
		a->mod_col_h = (a->mod_col_h & 0xFF00FF);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
