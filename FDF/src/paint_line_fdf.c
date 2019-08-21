/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_line_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:09:25 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/01 11:16:35 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		lead_up_for_paint_fdf(t_fdfstr *a)
{
	a->fd = 0;
	a->b_delta_x = abs(a->b_x2 - a->b_x1);
	a->b_delta_y = abs(a->b_y2 - a->b_y1);
	a->b_sign_x = a->b_x1 < a->b_x2 ? 1 : -1;
	a->b_sign_y = a->b_y1 < a->b_y2 ? 1 : -1;
	a->b_err1 = a->b_delta_x - a->b_delta_y;
}

int			r_fdf(double x)
{
	int		a;

	a = (int)x;
	x = x - a;
	if (x > 0)
	{
		if (x > 0.5)
			return (a + 1);
		else
			return (a);
	}
	if (x < -0.5)
		return (a - 1);
	return (a);
}

void		change_color_fdf(t_fdfstr *a)
{
	a->b_col_go = 0;
	a->b_col_go += (a->b_col_st & 0xFF0000) +
			(r_fdf(a->b_col_rst * a->b_col_per * a->fd) << 16);
	a->b_col_go += (a->b_col_st & 0xFF00) +
			(r_fdf(a->b_col_bst * a->b_col_per * a->fd) << 8);
	a->b_col_go += (a->b_col_st & 0xFF) +
			r_fdf(a->b_col_gst * a->b_col_per * a->fd);
}

void		paint_line_fdf(t_fdfstr *a)
{
	lead_up_for_paint_fdf(a);
	while (a->b_x1 != a->b_x2 || a->b_y1 != a->b_y2)
	{
		a->fd++;
		if (a->b_x1 >= 0 && a->b_y1 >= 0 && a->b_y1 < a->size_win_y
				&& a->b_x1 < a->size_win_x)
			*(int *)(a->img_ptr + ((a->b_x1 + a->b_y1 * a->size_win_x) *
					a->bpp)) = r_fdf(a->b_col_go);
		change_color_fdf(a);
		a->b_err2 = a->b_err1 * 2;
		if (a->b_err2 > -a->b_delta_y)
		{
			a->b_err1 -= a->b_delta_y;
			a->b_x1 += a->b_sign_x;
		}
		if (a->b_err2 < a->b_delta_x)
		{
			a->b_err1 += a->b_delta_x;
			a->b_y1 += a->b_sign_y;
		}
	}
}
