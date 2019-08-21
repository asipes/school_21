/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_preset10_fdf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:08:08 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/27 17:25:08 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		more_preset12_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 120)
		a->mod_color = 0xFFBBFF;
	else if (a->touch_3 == 121)
		a->mod_color = 0xFFFF00;
	else if (a->touch_3 == 122)
		a->mod_color = 0xFFFF33;
	else if (a->touch_3 == 123)
		a->mod_color = 0xFFFF88;
	else if (a->touch_3 == 124)
		a->mod_color = 0xFFFFBB;
	else if (a->touch_3 == 125)
		a->mod_color = 0xFFFFFF;
	else if (a->touch_3 == 126)
	{
		a->mod_color = 0;
		a->touch_3 = 1;
	}
}

void		more_preset11_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 110)
		a->mod_color = 0xFF33FF;
	else if (a->touch_3 == 111)
		a->mod_color = 0xFF8800;
	else if (a->touch_3 == 112)
		a->mod_color = 0xFF8833;
	else if (a->touch_3 == 113)
		a->mod_color = 0xFF8888;
	else if (a->touch_3 == 114)
		a->mod_color = 0xFF88BB;
	else if (a->touch_3 == 115)
		a->mod_color = 0xFF88FF;
	else if (a->touch_3 == 116)
		a->mod_color = 0xFFBB00;
	else if (a->touch_3 == 117)
		a->mod_color = 0xFFBB33;
	else if (a->touch_3 == 118)
		a->mod_color = 0xFFBB88;
	else if (a->touch_3 == 119)
		a->mod_color = 0xFFBBBB;
	else
		more_preset12_fdf(a);
}

void		more_preset10_fdf(t_fdfstr *a)
{
	if (a->touch_3 == 100)
		a->mod_color = 0xBBFFBB;
	else if (a->touch_3 == 101)
		a->mod_color = 0xBBFFFF;
	else if (a->touch_3 == 102)
		a->mod_color = 0xFF0033;
	else if (a->touch_3 == 103)
		a->mod_color = 0xFF0088;
	else if (a->touch_3 == 104)
		a->mod_color = 0xFF00BB;
	else if (a->touch_3 == 105)
		a->mod_color = 0xFF00FF;
	else if (a->touch_3 == 106)
		a->mod_color = 0xFF3300;
	else if (a->touch_3 == 107)
		a->mod_color = 0xFF3333;
	else if (a->touch_3 == 108)
		a->mod_color = 0xFF3388;
	else if (a->touch_3 == 109)
		a->mod_color = 0xFF33BB;
	else
		more_preset11_fdf(a);
}
