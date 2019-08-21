/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_b_color_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 22:11:25 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:39 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		many_r_color_fdf(t_fdfstr *a)
{
	if (((a->mod_color >> 16) - a->mod_step) >= 0)
		a->mod_color -= a->mod_step << 16;
	else
		a->mod_color = (a->mod_color & 0xFFFF);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_g_color_fdf(t_fdfstr *a)
{
	if ((((a->mod_color >> 8) & 0xFF) + a->mod_step) <= 255)
		a->mod_color += a->mod_step << 8;
	else
		a->mod_color = (255 << 8) + (a->mod_color & 0xFF00FF);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_g_color_fdf(t_fdfstr *a)
{
	if ((((a->mod_color >> 8) & 0xFF) - a->mod_step) >= 0)
		a->mod_color -= a->mod_step << 8;
	else
		a->mod_color = (a->mod_color & 0xFF00FF);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_b_color_fdf(t_fdfstr *a)
{
	if (((a->mod_color & 0xFF) + a->mod_step) <= 255)
		a->mod_color += a->mod_step;
	else
		a->mod_color = 255 + (a->mod_color & 0xFFFF00);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_b_color_fdf(t_fdfstr *a)
{
	if (((a->mod_color & 0xFF) - a->mod_step) >= 0)
		a->mod_color -= a->mod_step;
	else
		a->mod_color = (a->mod_color & 0xFFFF00);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
