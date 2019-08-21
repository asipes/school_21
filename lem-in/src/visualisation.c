/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:41:00 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/08/08 15:48:34 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	visualisation_1_1(t_lem_in *a)
{
	a->v->rooms[0][2] = 1;
	a->v->rooms[a->s_rooms - 1][2] = 3;
	a->v->ca = 0;
	a->v->rooms[a->s_rooms - 1][0] = a->v->w_x - 10;
	a->v->rooms[a->s_rooms - 1][1] = a->v->w_z - 10;
	a->v->rooms[0][0] = 10;
	a->v->rooms[0][1] = 10;
}

void	visualisation_1(t_lem_in *a)
{
	calc_rooms(a, 0, 1);
	a->v->ca = 0;
	a->cb = 0;
	a->cd = 0;
	while (a->v->ca < a->s_rooms)
	{
		a->v->rooms[a->v->ca] = (int *)malloc(sizeof(int) * 3);
		a->v->rooms[a->v->ca][2] = 2;
		a->v->rooms[a->v->ca][0] = a->cb * a->v->size + a->v->mid;
		a->v->rooms[a->v->ca][1] = a->cd * a->v->size + a->v->mid;
		a->cb++;
		if (a->cb > a->cc * 2)
		{
			a->cb = 0;
			a->cd++;
		}
		a->v->ca++;
	}
	visualisation_1_1(a);
	visualisation_2(a);
}

void	visualisation(t_lem_in *a)
{
	a->v = (t_vis *)malloc(sizeof(t_vis));
	a->v->mlx_ptr = mlx_init();
	a->v->w_x = 1650;
	a->v->w_y = 800;
	a->v->w_z = 850;
	a->v->a_x = 6;
	a->v->a_y = 6;
	a->v->ce = 90;
	a->v->win_ptr = mlx_new_window(a->v->mlx_ptr, a->v->w_x, a->v->w_z,
				"Lem-in");
	a->v->img_ptr_m = mlx_new_image(a->v->mlx_ptr, a->v->w_x, a->v->w_z);
	a->v->img_adr_m = mlx_get_data_addr(a->v->img_ptr_m, &a->v->bpp,
					&a->v->stride, &a->v->endian);
	a->v->img_ptr_a = mlx_new_image(a->v->mlx_ptr, a->v->a_x, a->v->a_y);
	a->v->img_adr_a = mlx_get_data_addr(a->v->img_ptr_a, &a->v->bpp,
					&a->v->stride, &a->v->endian);
	a->v->rooms = (int **)malloc(sizeof(int *) * a->s_rooms);
	a->v->ants = (int **)malloc(sizeof(int *) * a->s_ants);
	a->v->bpp /= 8;
	visualisation_1(a);
}
