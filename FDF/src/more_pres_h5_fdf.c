/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_pres_h5_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:56:54 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/30 17:59:04 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		more_pres_h9_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 90)
		a->mod_col_h = 0xBB88BB;
	else if (a->touch_4 == 91)
		a->mod_col_h = 0xBB88FF;
	else if (a->touch_4 == 92)
		a->mod_col_h = 0xBBBB00;
	else if (a->touch_4 == 93)
		a->mod_col_h = 0xBBBB33;
	else if (a->touch_4 == 94)
		a->mod_col_h = 0xBBBB88;
	else if (a->touch_4 == 95)
		a->mod_col_h = 0xBBBBBB;
	else if (a->touch_4 == 96)
		a->mod_col_h = 0xBBBBFF;
	else if (a->touch_4 == 97)
		a->mod_col_h = 0xBBFF00;
	else if (a->touch_4 == 98)
		a->mod_col_h = 0xBBFF33;
	else if (a->touch_4 == 99)
		a->mod_col_h = 0xBBFF88;
	else
		more_pres_h10_fdf(a);
}

void		more_pres_h8_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 80)
		a->mod_col_h = 0xBB00BB;
	else if (a->touch_4 == 81)
		a->mod_col_h = 0xBB00FF;
	else if (a->touch_4 == 82)
		a->mod_col_h = 0xBB3300;
	else if (a->touch_4 == 83)
		a->mod_col_h = 0xBB3333;
	else if (a->touch_4 == 84)
		a->mod_col_h = 0xBB3388;
	else if (a->touch_4 == 85)
		a->mod_col_h = 0xBB33BB;
	else if (a->touch_4 == 86)
		a->mod_col_h = 0xBB33FF;
	else if (a->touch_4 == 87)
		a->mod_col_h = 0xBB8800;
	else if (a->touch_4 == 88)
		a->mod_col_h = 0xBB8833;
	else if (a->touch_4 == 89)
		a->mod_col_h = 0xBB8888;
	else
		more_pres_h9_fdf(a);
}

void		more_pres_h7_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 70)
		a->mod_col_h = 0x88BB88;
	else if (a->touch_4 == 71)
		a->mod_col_h = 0x88BBBB;
	else if (a->touch_4 == 72)
		a->mod_col_h = 0x88BBFF;
	else if (a->touch_4 == 73)
		a->mod_col_h = 0x88FF00;
	else if (a->touch_4 == 74)
		a->mod_col_h = 0x88FF33;
	else if (a->touch_4 == 75)
		a->mod_col_h = 0x88FF88;
	else if (a->touch_4 == 76)
		a->mod_col_h = 0x88FFBB;
	else if (a->touch_4 == 77)
		a->mod_col_h = 0x88FFFF;
	else if (a->touch_4 == 78)
		a->mod_col_h = 0xBB0033;
	else if (a->touch_4 == 79)
		a->mod_col_h = 0xBB0088;
	else
		more_pres_h8_fdf(a);
}

void		more_pres_h6_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 60)
		a->mod_col_h = 0x883388;
	else if (a->touch_4 == 61)
		a->mod_col_h = 0x8833BB;
	else if (a->touch_4 == 62)
		a->mod_col_h = 0x8833FF;
	else if (a->touch_4 == 63)
		a->mod_col_h = 0x888800;
	else if (a->touch_4 == 64)
		a->mod_col_h = 0x888833;
	else if (a->touch_4 == 65)
		a->mod_col_h = 0x888888;
	else if (a->touch_4 == 66)
		a->mod_col_h = 0x8888BB;
	else if (a->touch_4 == 67)
		a->mod_col_h = 0x8888FF;
	else if (a->touch_4 == 68)
		a->mod_col_h = 0x88BB00;
	else if (a->touch_4 == 69)
		a->mod_col_h = 0x88BB33;
	else
		more_pres_h7_fdf(a);
}

void		more_pres_h5_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 50)
		a->mod_col_h = 0x33FF33;
	else if (a->touch_4 == 51)
		a->mod_col_h = 0x33FF88;
	else if (a->touch_4 == 52)
		a->mod_col_h = 0x33FFBB;
	else if (a->touch_4 == 53)
		a->mod_col_h = 0x33FFFF;
	else if (a->touch_4 == 54)
		a->mod_col_h = 0x880033;
	else if (a->touch_4 == 55)
		a->mod_col_h = 0x880088;
	else if (a->touch_4 == 56)
		a->mod_col_h = 0x8800BB;
	else if (a->touch_4 == 57)
		a->mod_col_h = 0x8800FF;
	else if (a->touch_4 == 58)
		a->mod_col_h = 0x883300;
	else if (a->touch_4 == 59)
		a->mod_col_h = 0x883333;
	else
		more_pres_h6_fdf(a);
}
