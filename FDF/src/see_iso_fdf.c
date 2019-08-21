/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_iso_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:22:29 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:25 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		see_norm_fdf(t_fdfstr *a)
{
	a->mod_see = 1;
	a->mod_hight = 1.0;
	a->betta = a->pi / 180 * 25;
	a->gamma = a->pi / 180 * 15;
	a->cetta = a->pi / 180 * 10;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		see_iso_fdf(t_fdfstr *a)
{
	a->betta = 0;
	a->gamma = 0;
	a->cetta = 0;
	a->mod_hight = 0.5;
	a->mod_see = 4;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		see_top_fdf(t_fdfstr *a)
{
	a->mod_see = 2;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		see_nice_fdf(t_fdfstr *a)
{
	a->mod_see = 3;
	a->mod_hight = 0.1;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
