/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say_good_buy_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:32:09 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:31 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			say_good_buy_fdf(t_fdfstr *a)
{
	mlx_destroy_window(a->mlx_ptr, a->win_ptr);
	a->c_a = 0;
	while (a->c_a < a->c_par)
	{
		free(a->arr[a->c_a]);
		a->c_a++;
	}
	free(a->arr);
	free(a);
	exit(0);
	return (0);
}

void		calk_mouse1_move_fdf(int x, int y, t_fdfstr *a)
{
	while (x < a->last_x1)
	{
		a->last_x1--;
		a->gamma -= a->pi / 360;
	}
	while (x > a->last_x1)
	{
		a->last_x1++;
		a->gamma += a->pi / 360;
	}
	while (y < a->last_y1)
	{
		a->last_y1--;
		a->betta += a->pi / 360;
	}
	while (y > a->last_y1)
	{
		a->last_y1++;
		a->betta -= a->pi / 360;
	}
}

void		calk_mouse2_move_fdf(int x, int y, t_fdfstr *a)
{
	while (x < a->last_x2)
	{
		a->last_x2--;
		a->s_x -= 1;
	}
	while (x > a->last_x2)
	{
		a->last_x2++;
		a->s_x += 1;
	}
	while (y < a->last_y2)
	{
		a->last_y2--;
		a->s_y -= 1;
	}
	while (y > a->last_y2)
	{
		a->last_y2++;
		a->s_y += 1;
	}
}

void		more_cetta_m_fdf(t_fdfstr *a)
{
	a->cetta += a->pi / 180 * 10;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}

void		many_cetta_m_fdf(t_fdfstr *a)
{
	a->cetta -= a->pi / 180 * 10;
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
