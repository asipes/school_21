/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_fdf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:02:37 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/02 17:11:30 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mouse_go_fdf(int x, int y, t_fdfstr *a)
{
	if (a->touch_1 == 1)
		calk_mouse1_move_fdf(x, y, a);
	if (a->touch_2 == 1)
		calk_mouse2_move_fdf(x, y, a);
	if (a->touch_1 == 1 || a->touch_2 == 1)
	{
		ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
		paint_map_fdf(a);
	}
	a->last_x1 = x;
	a->last_y1 = y;
	a->last_x2 = x;
	a->last_y2 = y;
	return (0);
}

int			mouse_dont_press_fdf(int mc, int x, int y, t_fdfstr *a)
{
	x = x + 0;
	y = y + 0;
	if (mc == 1)
		a->touch_1 = 0;
	if (mc == 2)
		a->touch_2 = 0;
	return (1);
}

int			mouse_press_fdf(int mc, int x, int y, t_fdfstr *a)
{
	x = x + 0;
	y = y + 0;
	if (mc == 4)
		more_cetta_m_fdf(a);
	else if (mc == 5)
		many_cetta_m_fdf(a);
	if (mc == 1)
		a->touch_1 = 1;
	if (mc == 2)
		a->touch_2 = 1;
	if (mc == 3)
	{
		a->touch_3++;
		color_preset_fdf(a);
	}
	return (0);
}
