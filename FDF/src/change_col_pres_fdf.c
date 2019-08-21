/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_col_pres_fdf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:17:56 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/30 18:19:38 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					change_col_pres_fdf(t_fdfstr *a)
{
	a->touch_3++;
	color_preset_fdf(a);
}

void					change_c_h_pres_fdf(t_fdfstr *a)
{
	a->touch_4++;
	color_pres_h_fdf(a);
}
