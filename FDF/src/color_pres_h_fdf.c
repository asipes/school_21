/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pres_h_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:54:53 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:46 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		more_pres_h4_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 40)
		a->mod_col_h = 0x338833;
	else if (a->touch_4 == 41)
		a->mod_col_h = 0x338888;
	else if (a->touch_4 == 42)
		a->mod_col_h = 0x3388BB;
	else if (a->touch_4 == 43)
		a->mod_col_h = 0x3388FF;
	else if (a->touch_4 == 44)
		a->mod_col_h = 0x33BB00;
	else if (a->touch_4 == 45)
		a->mod_col_h = 0x33BB33;
	else if (a->touch_4 == 46)
		a->mod_col_h = 0x33BB88;
	else if (a->touch_4 == 47)
		a->mod_col_h = 0x33BBBB;
	else if (a->touch_4 == 48)
		a->mod_col_h = 0x33BBFF;
	else if (a->touch_4 == 49)
		a->mod_col_h = 0x33FF00;
	else
		more_pres_h5_fdf(a);
}

void		more_pres_h3_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 30)
		a->mod_col_h = 0x330033;
	else if (a->touch_4 == 31)
		a->mod_col_h = 0x330088;
	else if (a->touch_4 == 32)
		a->mod_col_h = 0x3300BB;
	else if (a->touch_4 == 33)
		a->mod_col_h = 0x3300FF;
	else if (a->touch_4 == 34)
		a->mod_col_h = 0x333300;
	else if (a->touch_4 == 35)
		a->mod_col_h = 0x333333;
	else if (a->touch_4 == 36)
		a->mod_col_h = 0x333388;
	else if (a->touch_4 == 37)
		a->mod_col_h = 0x3333BB;
	else if (a->touch_4 == 38)
		a->mod_col_h = 0x3333FF;
	else if (a->touch_4 == 39)
		a->mod_col_h = 0x338800;
	else
		more_pres_h4_fdf(a);
}

void		more_pres_h2_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 20)
		a->mod_col_h = 0x88BB;
	else if (a->touch_4 == 21)
		a->mod_col_h = 0x88FF;
	else if (a->touch_4 == 22)
		a->mod_col_h = 0xBB33;
	else if (a->touch_4 == 23)
		a->mod_col_h = 0xBB88;
	else if (a->touch_4 == 24)
		a->mod_col_h = 0xBBBB;
	else if (a->touch_4 == 25)
		a->mod_col_h = 0xBBFF;
	else if (a->touch_4 == 26)
		a->mod_col_h = 0xFF33;
	else if (a->touch_4 == 27)
		a->mod_col_h = 0xFF88;
	else if (a->touch_4 == 28)
		a->mod_col_h = 0xFFBB;
	else if (a->touch_4 == 29)
		a->mod_col_h = 0xFFFF;
	else
		more_pres_h3_fdf(a);
}

void		more_pres_h1_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 10)
		a->mod_col_h = 0x330000;
	else if (a->touch_4 == 11)
		a->mod_col_h = 0x880000;
	else if (a->touch_4 == 12)
		a->mod_col_h = 0xBB0000;
	else if (a->touch_4 == 13)
		a->mod_col_h = 0xFF0000;
	else if (a->touch_4 == 14)
		a->mod_col_h = 0x3333;
	else if (a->touch_4 == 15)
		a->mod_col_h = 0x3388;
	else if (a->touch_4 == 16)
		a->mod_col_h = 0x33BB;
	else if (a->touch_4 == 17)
		a->mod_col_h = 0x33FF;
	else if (a->touch_4 == 18)
		a->mod_col_h = 0x8833;
	else if (a->touch_4 == 19)
		a->mod_col_h = 0x8888;
	else
		more_pres_h2_fdf(a);
}

void		color_pres_h_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 1)
		a->mod_col_h = 0;
	else if (a->touch_4 == 2)
		a->mod_col_h = 0x33;
	else if (a->touch_4 == 3)
		a->mod_col_h = 0x88;
	else if (a->touch_4 == 4)
		a->mod_col_h = 0xBB;
	else if (a->touch_4 == 5)
		a->mod_col_h = 0xFF;
	else if (a->touch_4 == 6)
		a->mod_col_h = 0x3300;
	else if (a->touch_4 == 7)
		a->mod_col_h = 0x8800;
	else if (a->touch_4 == 8)
		a->mod_col_h = 0xBB00;
	else if (a->touch_4 == 9)
		a->mod_col_h = 0xFF00;
	else
		more_pres_h1_fdf(a);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
