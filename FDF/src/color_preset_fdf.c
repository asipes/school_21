/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_preset_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:08:41 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/31 23:23:45 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		more_preset4_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 40)
		a->mod_color = 0x338833;
	else if (a->touch_3 == 41)
		a->mod_color = 0x338888;
	else if (a->touch_3 == 42)
		a->mod_color = 0x3388BB;
	else if (a->touch_3 == 43)
		a->mod_color = 0x3388FF;
	else if (a->touch_3 == 44)
		a->mod_color = 0x33BB00;
	else if (a->touch_3 == 45)
		a->mod_color = 0x33BB33;
	else if (a->touch_3 == 46)
		a->mod_color = 0x33BB88;
	else if (a->touch_3 == 47)
		a->mod_color = 0x33BBBB;
	else if (a->touch_3 == 48)
		a->mod_color = 0x33BBFF;
	else if (a->touch_3 == 49)
		a->mod_color = 0x33FF00;
	else
		more_preset5_fdf(a);
}

void		more_preset3_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 30)
		a->mod_color = 0x330033;
	else if (a->touch_3 == 31)
		a->mod_color = 0x330088;
	else if (a->touch_3 == 32)
		a->mod_color = 0x3300BB;
	else if (a->touch_3 == 33)
		a->mod_color = 0x3300FF;
	else if (a->touch_3 == 34)
		a->mod_color = 0x333300;
	else if (a->touch_3 == 35)
		a->mod_color = 0x333333;
	else if (a->touch_3 == 36)
		a->mod_color = 0x333388;
	else if (a->touch_3 == 37)
		a->mod_color = 0x3333BB;
	else if (a->touch_3 == 38)
		a->mod_color = 0x3333FF;
	else if (a->touch_3 == 39)
		a->mod_color = 0x338800;
	else
		more_preset4_fdf(a);
}

void		more_preset2_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 20)
		a->mod_color = 0x88BB;
	else if (a->touch_3 == 21)
		a->mod_color = 0x88FF;
	else if (a->touch_3 == 22)
		a->mod_color = 0xBB33;
	else if (a->touch_3 == 23)
		a->mod_color = 0xBB88;
	else if (a->touch_3 == 24)
		a->mod_color = 0xBBBB;
	else if (a->touch_3 == 25)
		a->mod_color = 0xBBFF;
	else if (a->touch_3 == 26)
		a->mod_color = 0xFF33;
	else if (a->touch_3 == 27)
		a->mod_color = 0xFF88;
	else if (a->touch_3 == 28)
		a->mod_color = 0xFFBB;
	else if (a->touch_3 == 29)
		a->mod_color = 0xFFFF;
	else
		more_preset3_fdf(a);
}

void		more_preset1_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 10)
		a->mod_color = 0x330000;
	else if (a->touch_3 == 11)
		a->mod_color = 0x880000;
	else if (a->touch_3 == 12)
		a->mod_color = 0xBB0000;
	else if (a->touch_3 == 13)
		a->mod_color = 0xFF0000;
	else if (a->touch_3 == 14)
		a->mod_color = 0x3333;
	else if (a->touch_3 == 15)
		a->mod_color = 0x3388;
	else if (a->touch_3 == 16)
		a->mod_color = 0x33BB;
	else if (a->touch_3 == 17)
		a->mod_color = 0x33FF;
	else if (a->touch_3 == 18)
		a->mod_color = 0x8833;
	else if (a->touch_3 == 19)
		a->mod_color = 0x8888;
	else
		more_preset2_fdf(a);
}

void		color_preset_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 1)
		a->mod_color = 0;
	else if (a->touch_3 == 2)
		a->mod_color = 0x33;
	else if (a->touch_3 == 3)
		a->mod_color = 0x88;
	else if (a->touch_3 == 4)
		a->mod_color = 0xBB;
	else if (a->touch_3 == 5)
		a->mod_color = 0xFF;
	else if (a->touch_3 == 6)
		a->mod_color = 0x3300;
	else if (a->touch_3 == 7)
		a->mod_color = 0x8800;
	else if (a->touch_3 == 8)
		a->mod_color = 0xBB00;
	else if (a->touch_3 == 9)
		a->mod_color = 0xFF00;
	else
		more_preset1_fdf(a);
	ft_bzero(a->img_ptr, a->size_win_x * a->size_win_y * 4);
	paint_map_fdf(a);
}
