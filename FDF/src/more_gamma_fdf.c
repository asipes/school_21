/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_gamma_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:26:42 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:36 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		more_gamma_fdf(t_fdfstr *a)
{
	a->gamma += a->pi / 180 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_cetta_fdf(t_fdfstr *a)
{
	a->cetta -= a->pi / 180 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_cetta_fdf(t_fdfstr *a)
{
	a->cetta += a->pi / 180 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_hight_fdf(t_fdfstr *a)
{
	a->mod_hight -= (double)0.1 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_hight_fdf(t_fdfstr *a)
{
	a->mod_hight += (double)0.1 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
