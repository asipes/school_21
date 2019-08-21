/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_pres_h10_fdf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:59:31 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/30 18:00:40 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		more_pres_h12_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 120)
		a->mod_col_h = 0xFFBBFF;
	else if (a->touch_4 == 121)
		a->mod_col_h = 0xFFFF00;
	else if (a->touch_4 == 122)
		a->mod_col_h = 0xFFFF33;
	else if (a->touch_4 == 123)
		a->mod_col_h = 0xFFFF88;
	else if (a->touch_4 == 124)
		a->mod_col_h = 0xFFFFBB;
	else if (a->touch_4 == 125)
		a->mod_col_h = 0xFFFFFF;
	else if (a->touch_4 == 126)
	{
		a->mod_col_h = 0;
		a->touch_4 = 1;
	}
}

void		more_pres_h11_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 110)
		a->mod_col_h = 0xFF33FF;
	else if (a->touch_4 == 111)
		a->mod_col_h = 0xFF8800;
	else if (a->touch_4 == 112)
		a->mod_col_h = 0xFF8833;
	else if (a->touch_4 == 113)
		a->mod_col_h = 0xFF8888;
	else if (a->touch_4 == 114)
		a->mod_col_h = 0xFF88BB;
	else if (a->touch_4 == 115)
		a->mod_col_h = 0xFF88FF;
	else if (a->touch_4 == 116)
		a->mod_col_h = 0xFFBB00;
	else if (a->touch_4 == 117)
		a->mod_col_h = 0xFFBB33;
	else if (a->touch_4 == 118)
		a->mod_col_h = 0xFFBB88;
	else if (a->touch_4 == 119)
		a->mod_col_h = 0xFFBBBB;
	else
		more_pres_h12_fdf(a);
}

void		more_pres_h10_fdf(t_fdfstr *a)
{
	if (a->touch_4 == 100)
		a->mod_col_h = 0xBBFFBB;
	else if (a->touch_4 == 101)
		a->mod_col_h = 0xBBFFFF;
	else if (a->touch_4 == 102)
		a->mod_col_h = 0xFF0033;
	else if (a->touch_4 == 103)
		a->mod_col_h = 0xFF0088;
	else if (a->touch_4 == 104)
		a->mod_col_h = 0xFF00BB;
	else if (a->touch_4 == 105)
		a->mod_col_h = 0xFF00FF;
	else if (a->touch_4 == 106)
		a->mod_col_h = 0xFF3300;
	else if (a->touch_4 == 107)
		a->mod_col_h = 0xFF3333;
	else if (a->touch_4 == 108)
		a->mod_col_h = 0xFF3388;
	else if (a->touch_4 == 109)
		a->mod_col_h = 0xFF33BB;
	else
		more_pres_h11_fdf(a);
}
