/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_alfa_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:25:37 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:40 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		many_alfa_fdf(t_fdfstr *a)
{
	a->alfa -= a->pi / 180 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_alfa_fdf(t_fdfstr *a)
{
	a->alfa += a->pi / 180 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_betta_fdf(t_fdfstr *a)
{
	a->betta -= a->pi / 180 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		more_betta_fdf(t_fdfstr *a)
{
	a->betta += a->pi / 180 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_gamma_fdf(t_fdfstr *a)
{
	a->gamma -= a->pi / 180 * a->mod_step;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
