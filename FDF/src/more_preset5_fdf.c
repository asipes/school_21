/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_preset5_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:06:49 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/27 17:25:04 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		more_preset9_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 90)
		a->mod_color = 0xBB88BB;
	else if (a->touch_3 == 91)
		a->mod_color = 0xBB88FF;
	else if (a->touch_3 == 92)
		a->mod_color = 0xBBBB00;
	else if (a->touch_3 == 93)
		a->mod_color = 0xBBBB33;
	else if (a->touch_3 == 94)
		a->mod_color = 0xBBBB88;
	else if (a->touch_3 == 95)
		a->mod_color = 0xBBBBBB;
	else if (a->touch_3 == 96)
		a->mod_color = 0xBBBBFF;
	else if (a->touch_3 == 97)
		a->mod_color = 0xBBFF00;
	else if (a->touch_3 == 98)
		a->mod_color = 0xBBFF33;
	else if (a->touch_3 == 99)
		a->mod_color = 0xBBFF88;
	else
		more_preset10_fdf(a);
}

void		more_preset8_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 80)
		a->mod_color = 0xBB00BB;
	else if (a->touch_3 == 81)
		a->mod_color = 0xBB00FF;
	else if (a->touch_3 == 82)
		a->mod_color = 0xBB3300;
	else if (a->touch_3 == 83)
		a->mod_color = 0xBB3333;
	else if (a->touch_3 == 84)
		a->mod_color = 0xBB3388;
	else if (a->touch_3 == 85)
		a->mod_color = 0xBB33BB;
	else if (a->touch_3 == 86)
		a->mod_color = 0xBB33FF;
	else if (a->touch_3 == 87)
		a->mod_color = 0xBB8800;
	else if (a->touch_3 == 88)
		a->mod_color = 0xBB8833;
	else if (a->touch_3 == 89)
		a->mod_color = 0xBB8888;
	else
		more_preset9_fdf(a);
}

void		more_preset7_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 70)
		a->mod_color = 0x88BB88;
	else if (a->touch_3 == 71)
		a->mod_color = 0x88BBBB;
	else if (a->touch_3 == 72)
		a->mod_color = 0x88BBFF;
	else if (a->touch_3 == 73)
		a->mod_color = 0x88FF00;
	else if (a->touch_3 == 74)
		a->mod_color = 0x88FF33;
	else if (a->touch_3 == 75)
		a->mod_color = 0x88FF88;
	else if (a->touch_3 == 76)
		a->mod_color = 0x88FFBB;
	else if (a->touch_3 == 77)
		a->mod_color = 0x88FFFF;
	else if (a->touch_3 == 78)
		a->mod_color = 0xBB0033;
	else if (a->touch_3 == 79)
		a->mod_color = 0xBB0088;
	else
		more_preset8_fdf(a);
}

void		more_preset6_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 60)
		a->mod_color = 0x883388;
	else if (a->touch_3 == 61)
		a->mod_color = 0x8833BB;
	else if (a->touch_3 == 62)
		a->mod_color = 0x8833FF;
	else if (a->touch_3 == 63)
		a->mod_color = 0x888800;
	else if (a->touch_3 == 64)
		a->mod_color = 0x888833;
	else if (a->touch_3 == 65)
		a->mod_color = 0x888888;
	else if (a->touch_3 == 66)
		a->mod_color = 0x8888BB;
	else if (a->touch_3 == 67)
		a->mod_color = 0x8888FF;
	else if (a->touch_3 == 68)
		a->mod_color = 0x88BB00;
	else if (a->touch_3 == 69)
		a->mod_color = 0x88BB33;
	else
		more_preset7_fdf(a);
}

void		more_preset5_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 50)
		a->mod_color = 0x33FF33;
	else if (a->touch_3 == 51)
		a->mod_color = 0x33FF88;
	else if (a->touch_3 == 52)
		a->mod_color = 0x33FFBB;
	else if (a->touch_3 == 53)
		a->mod_color = 0x33FFFF;
	else if (a->touch_3 == 54)
		a->mod_color = 0x880033;
	else if (a->touch_3 == 55)
		a->mod_color = 0x880088;
	else if (a->touch_3 == 56)
		a->mod_color = 0x8800BB;
	else if (a->touch_3 == 57)
		a->mod_color = 0x8800FF;
	else if (a->touch_3 == 58)
		a->mod_color = 0x883300;
	else if (a->touch_3 == 59)
		a->mod_color = 0x883333;
	else
		more_preset6_fdf(a);
}
