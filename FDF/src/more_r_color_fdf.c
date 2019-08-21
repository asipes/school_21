/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_r_color_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 22:12:32 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:34 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		map_right_fdf(t_fdfstr *a)
{
	a->s_x += a->mod_step * a->mod_see;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		map_left_fdf(t_fdfstr *a)
{
	a->s_x -= a->mod_step * a->mod_see;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_step_fdf(t_fdfstr *a)
{
	a->mod_step++;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_step_fdf(t_fdfstr *a)
{
	a->mod_step--;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_r_color_fdf(t_fdfstr *a)
{
	if (((a->mod_color >> 16) + a->mod_step) <= 255)
		a->mod_color += a->mod_step << 16;
	else
		a->mod_color = (255 << 16) + (a->mod_color & 0xFFFF);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
