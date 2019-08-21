/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:23:27 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/08/08 15:51:20 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	calc_rooms(t_lem_in *a, int i, int j)
{
	i = a->v->w_y * a->v->w_y / (a->s_rooms / 2);
	while (j * j <= i)
	{
		j++;
	}
	j--;
	a->v->size = j;
	a->cc = a->v->w_y / a->v->size;
	if (j < 12)
	{
		a->fv = 0;
		vis_or_dont_vis(a, 0, 0);
		if (a->fc)
			ft_printf("\nSteps: %i\n", a->turn - 1);
		lem_exit(0, a);
	}
	a->v->mid = 25;
}

void	brez_line(t_lem_in *a)
{
	a->v->fd = 0;
	a->v->b_delta_x = abs(a->v->b_x2 - a->v->b_x1);
	a->v->b_delta_y = abs(a->v->b_y2 - a->v->b_y1);
	a->v->b_sign_x = a->v->b_x1 < a->v->b_x2 ? 1 : -1;
	a->v->b_sign_y = a->v->b_y1 < a->v->b_y2 ? 1 : -1;
	a->v->b_err1 = a->v->b_delta_x - a->v->b_delta_y;
	while (a->v->b_x1 != a->v->b_x2 || a->v->b_y1 != a->v->b_y2)
	{
		a->v->fd++;
		if (a->v->b_x1 >= 0 && a->v->b_y1 >= 0 && a->v->b_y1 < a->v->w_z
				&& a->v->b_x1 < a->v->w_x)
			*(int *)(a->v->img_adr_m + ((a->v->b_x1 + a->v->b_y1 * a->v->w_x) *
					a->v->bpp)) = a->v->color / 2;
		a->v->b_err2 = a->v->b_err1 * 2;
		if (a->v->b_err2 > -a->v->b_delta_y)
		{
			a->v->b_err1 -= a->v->b_delta_y;
			a->v->b_x1 += a->v->b_sign_x;
		}
		if (a->v->b_err2 < a->v->b_delta_x)
		{
			a->v->b_err1 += a->v->b_delta_x;
			a->v->b_y1 += a->v->b_sign_y;
		}
	}
}

void	put_ways(t_lem_in *a)
{
	a->cb = a->ca;
	while (a->cb < a->s_rooms)
	{
		if (a->a_conn[a->ca][a->cb])
		{
			a->v->b_x1 = a->v->rooms[a->ca][0];
			a->v->b_y1 = a->v->rooms[a->ca][1];
			a->v->b_x2 = a->v->rooms[a->cb][0];
			a->v->b_y2 = a->v->rooms[a->cb][1];
			a->v->color = (0xFFFF / a->s_rooms) * a->cb;
			brez_line(a);
		}
		a->cb++;
	}
	a->ca++;
}

void	start_room(t_lem_in *a, int i, int j, int k)
{
	int	l;

	l = -5;
	while (l < 5)
	{
		if (l == -5 || l == 4 || k == -5 || k == 4 || ((l == -4 || l == 3)
		&& (k > -3 && k < 2)) || ((k == -4 || k == 3) && (l > -3 && l < 2)))
			a->v->color = 0x276468;
		else
			a->v->color = 0x3c9f9c;
		*(int *)(a->v->img_adr_m + ((i - k + (j - l) * a->v->w_x) *
					a->v->bpp)) = a->v->color;
		k++;
		if (k == 5)
		{
			k = -5;
			l++;
		}
	}
}

void	end_room(t_lem_in *a, int i, int j, int k)
{
	int	l;

	l = -5;
	while (l < 5)
	{
		if (l == -5 || l == 4 || k == -5 || k == 4 || ((l == -4 || l == 3)
		&& (k > -3 && k < 2)) || ((k == -4 || k == 3) && (l > -3 && l < 2)))
			a->v->color = 0x3c9f9c;
		else
			a->v->color = 0x276468;
		*(int *)(a->v->img_adr_m + ((i - k + (j - l) * a->v->w_x) *
					a->v->bpp)) = a->v->color;
		k++;
		if (k == 5)
		{
			k = -5;
			l++;
		}
	}
}
