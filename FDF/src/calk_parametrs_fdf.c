/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calk_parametrs_fdf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 00:18:10 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/01 11:18:33 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calk_parametrs_fdf(t_fdfstr *a)
{
	a->x1 = (a->arr[a->c_a][0] - a->c_stl / 2) * a->mod_size;
	a->y1 = (a->arr[a->c_a][1] - a->c_str / 2) * a->mod_size;
	a->z1 = a->arr[a->c_a][2] * a->mod_hight * a->mod_size;
	if (a->z1 > a->max_z)
		a->max_z = a->z1;
	if (a->z1 < a->min_z)
		a->min_z = a->z1;
	a->arr[a->c_a][4] = r_fdf(a->x1 * cos(a->gamma) +
			a->z1 * sin(a->gamma));
	a->arr[a->c_a][6] = r_fdf(a->z1 * cos(a->gamma) -
			a->x1 * sin(a->gamma));
	a->z1 = a->arr[a->c_a][6];
	a->arr[a->c_a][5] = r_fdf(a->y1 * cos(a->betta) -
			a->z1 * sin(a->betta));
	a->arr[a->c_a][6] = r_fdf(a->z1 * cos(a->betta) +
			a->y1 * sin(a->betta));
	a->x1 = a->arr[a->c_a][4];
	a->y1 = a->arr[a->c_a][5];
	a->arr[a->c_a][4] = r_fdf(a->x1 * cos(a->cetta) -
			a->y1 * sin(a->cetta));
	a->arr[a->c_a][5] = r_fdf(a->y1 * cos(a->cetta) +
			a->x1 * sin(a->cetta));
}
