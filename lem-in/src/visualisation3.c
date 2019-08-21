/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:29:14 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/08/08 15:49:21 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		go_do_this_3(t_lem_in *a, int i, int j)
{
	a->v->ants[i][0] = a->v->rooms[a->step_ants[i][2]][0] - 2;
	a->v->ants[i][1] = a->v->rooms[a->step_ants[i][2]][1] - 2;
	a->step_ants[i][2] =
				a->w_run->ways[a->step_ants[i][1]]->way[j + 1];
	a->v->ants[i][2] = a->v->rooms[a->step_ants[i][2]][0] - 2;
	a->v->ants[i][3] = a->v->rooms[a->step_ants[i][2]][1] - 2;
}

void		go_do_this_4_2(t_lem_in *a)
{
	a->v->ca = 0;
	while (a->v->ca < a->s_ants)
	{
		a->v->ants[a->v->ca][0] = a->v->ants[a->v->ca][2];
		a->v->ants[a->v->ca][1] = a->v->ants[a->v->ca][3];
		a->v->ca++;
	}
	ft_putchar('\n');
	go_do_this_2(a, 0, 0);
}

int			go_do_this_4(t_lem_in *a)
{
	float x;
	float y;

	if (a->fv && a->cb <= a->v->ce)
	{
		a->v->ca = 0;
		mlx_put_image_to_window(a->v->mlx_ptr, a->v->win_ptr,
				a->v->img_ptr_m, 0, 0);
		while (a->v->ca < a->s_ants)
		{
			x = ((a->v->ants[a->v->ca][2] - a->v->ants[a->v->ca][0]) /
					(float)a->v->ce) * a->cb + a->v->ants[a->v->ca][0];
			y = ((a->v->ants[a->v->ca][3] - a->v->ants[a->v->ca][1]) /
					(float)a->v->ce) * a->cb + a->v->ants[a->v->ca][1];
			mlx_put_image_to_window(a->v->mlx_ptr, a->v->win_ptr,
					a->v->img_ptr_a, (int)x, (int)y);
			a->v->ca++;
		}
		a->cb++;
	}
	else
		go_do_this_4_2(a);
	return (0);
}

void		go_do_this_5(t_lem_in *a)
{
	if (a->fv && a->cb <= a->v->ce)
	{
		mlx_loop_hook(a->v->mlx_ptr, go_do_this_4, a);
		mlx_hook(a->v->win_ptr, 2, 2, key_press, a);
		mlx_hook(a->v->win_ptr, 17, 17, say_good_buy, a);
		mlx_loop(a->v->mlx_ptr);
	}
	else
	{
		if (a->fv == 0)
			ft_putchar('\n');
		go_do_this_2(a, 0, 0);
	}
}

void		go_do_this_2_2(t_lem_in *a)
{
	if (a->fc)
	{
		ft_printf("\nSteps: %i\n", a->turn - 1);
	}
	a->fc = 2;
	if (a->fv == 0)
		lem_exit(0, a);
}
