/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lt_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:19:37 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:38 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		map_lt_fdf(t_fdfstr *a)
{
	a->s_y -= a->mod_step * a->mod_see;
	a->s_x -= a->mod_step * a->mod_see;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		map_rt_fdf(t_fdfstr *a)
{
	a->s_y -= a->mod_step * a->mod_see;
	a->s_x += a->mod_step * a->mod_see;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		map_ld_fdf(t_fdfstr *a)
{
	a->s_y += a->mod_step * a->mod_see;
	a->s_x -= a->mod_step * a->mod_see;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		map_rd_fdf(t_fdfstr *a)
{
	a->s_y += a->mod_step * a->mod_see;
	a->s_x += a->mod_step * a->mod_see;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
