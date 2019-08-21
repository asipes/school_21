/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_top_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 22:13:56 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:37 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		more_map_size_fdf(t_fdfstr *a)
{
	a->mod_size += a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_map_size_fdf(t_fdfstr *a)
{
	if ((a->mod_size - a->mod_step) > 1)
		a->mod_size -= a->mod_step;
	else
		a->mod_size = 1;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		map_down_fdf(t_fdfstr *a)
{
	a->s_y += a->mod_step * a->mod_see;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		map_top_fdf(t_fdfstr *a)
{
	a->s_y -= a->mod_step * a->mod_see;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
