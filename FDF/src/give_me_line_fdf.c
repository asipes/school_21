/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_me_line_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:05:10 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/01 01:55:43 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		color_zero_fdf(t_fdfstr *a)
{
	a->b_col_rst = 0;
	a->b_col_bst = 0;
	a->b_col_gst = 0;
}

void		calc_col_step_p2_fdf(t_fdfstr *a)
{
	if (((a->b_col_st & 0xFF0000) - (a->b_col_end & 0xFF0000)) > 0)
		a->b_col_rst = -((a->b_col_st >> 16) - (a->b_col_end >> 16));
	else
		a->b_col_rst = (a->b_col_end >> 16) - (a->b_col_st >> 16);
	if (((a->b_col_st & 0xFF00) - (a->b_col_end & 0xFF00)) > 0)
		a->b_col_bst = -(((a->b_col_st >> 8) & 0xFF) -
				((a->b_col_end >> 8) & 0xFF));
	else
		a->b_col_bst = (((a->b_col_end >> 8) & 0xFF) -
				((a->b_col_st >> 8) & 0xFF));
	if (((a->b_col_st & 0xFF) - (a->b_col_end & 0xFF)) > 0)
		a->b_col_gst = -((a->b_col_st & 0xFF) - (a->b_col_end & 0xFF));
	else
		a->b_col_gst = (a->b_col_end & 0xFF) - (a->b_col_st & 0xFF);
	a->b_col_per = (double)1 / (double)(a->fd);
	a->b_col_go = a->b_col_st;
}

void		calc_color_step_fdf(t_fdfstr *a)
{
	lead_up_for_paint_fdf(a);
	while (a->b_x1 != a->b_x2 || a->b_y1 != a->b_y2)
	{
		a->fd++;
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
	calc_col_step_p2_fdf(a);
}

void		give_me_line_p2_fdf(t_fdfstr *a)
{
	a->b_x1 = a->arr[a->c_a - 1][4];
	a->b_y1 = a->arr[a->c_a - 1][5];
	a->b_x2 = a->arr[a->c_a][4];
	a->b_y2 = a->arr[a->c_a][5];
	a->b_col_st = a->arr[a->c_a - 1][3] > -1 ? a->arr[a->c_a - 1][3]
			: ch_fdf(a, a->arr[a->c_a - 1][2]);
	a->b_col_end = a->arr[a->c_a][3] > -1 ? a->arr[a->c_a][3] :
			ch_fdf(a, a->arr[a->c_a][2]);
	if (a->b_col_st - a->b_col_end)
		calc_color_step_fdf(a);
	else
		color_zero_fdf(a);
	a->b_x1 = a->arr[a->c_a - 1][4];
	a->b_y1 = a->arr[a->c_a - 1][5];
	a->b_x2 = a->arr[a->c_a][4];
	a->b_y2 = a->arr[a->c_a][5];
	paint_line_fdf(a);
}

void		gevi_me_line_fdf(t_fdfstr *a)
{
	if (a->arr[a->c_a][1] != 0)
	{
		a->b_x1 = a->arr[a->c_a - a->c_stl][4];
		a->b_y1 = a->arr[a->c_a - a->c_stl][5];
		a->b_x2 = a->arr[a->c_a][4];
		a->b_y2 = a->arr[a->c_a][5];
		a->b_col_st = a->arr[a->c_a - a->c_stl][3] > -1 ?
			a->arr[a->c_a - a->c_stl][3] :
				ch_fdf(a, a->arr[a->c_a - a->c_stl][2]);
		a->b_col_end = a->arr[a->c_a][3] > -1 ? a->arr[a->c_a][3]
				: ch_fdf(a, a->arr[a->c_a][2]);
		if (a->b_col_st - a->b_col_end)
			calc_color_step_fdf(a);
		else
			color_zero_fdf(a);
		a->b_x1 = a->arr[a->c_a - a->c_stl][4];
		a->b_y1 = a->arr[a->c_a - a->c_stl][5];
		a->b_x2 = a->arr[a->c_a][4];
		a->b_y2 = a->arr[a->c_a][5];
		paint_line_fdf(a);
	}
	if (a->arr[a->c_a][0] != 0)
		give_me_line_p2_fdf(a);
}
