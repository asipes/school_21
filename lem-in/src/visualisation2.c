/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:28:40 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/08/08 15:49:43 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	middle_room(t_lem_in *a, int i, int j, int k)
{
	int	l;

	l = -2;
	while (l < 3)
	{
		if (l == -2 || l == 2 || k == -2 || k == 2)
			a->v->color = 0x276468;
		else
			a->v->color = 0x3c9f9c;
		*(int *)(a->v->img_adr_m + ((i - k + (j - l) * a->v->w_x) *
					a->v->bpp)) = a->v->color;
		k++;
		if (k == 3)
		{
			k = -2;
			l++;
		}
	}
}

void	put_rooms_v(t_lem_in *a)
{
	a->ca = 0;
	while (a->ca < a->s_rooms)
	{
		if (a->ca == 0)
			start_room(a, a->v->rooms[a->ca][0], a->v->rooms[a->ca][1], -5);
		else if (a->ca == a->s_rooms - 1)
			end_room(a, a->v->rooms[a->ca][0], a->v->rooms[a->ca][1], -5);
		else
			middle_room(a, a->v->rooms[a->ca][0], a->v->rooms[a->ca][1], -2);
		a->ca++;
	}
}

void	get_ants_image(t_lem_in *a, int i, int j)
{
	while (j < 6)
	{
		if (i == 0 || i == 5 || j == 0 || j == 5 || i == 3 ||
				(i == 1 && j == 2) || (i == 2 && j == 3))
			*(int *)(a->v->img_adr_a + ((i + j * a->v->a_x) *
					a->v->bpp)) = 0xFFFFFF;
		else
			*(int *)(a->v->img_adr_a + ((i + j * a->v->a_x) *
					a->v->bpp)) = 0x0;
		i++;
		if (i == 6)
		{
			i = 0;
			j++;
		}
	}
}

int		say_good_buy(t_lem_in *a)
{
	mlx_destroy_window(a->v->mlx_ptr, a->v->win_ptr);
	a->fv = 0;
	if (a->fc == 2)
		lem_exit(0, a);
	return (0);
}

int		key_press(int key, t_lem_in *a)
{
	if (key == 53)
		say_good_buy(a);
	else if (key == 49)
		sleep(1);
	else if (key == 27)
		a->v->ce += 4;
	else if (key == 24 && a->v->ce > 4)
		a->v->ce -= 4;
	return (0);
}
