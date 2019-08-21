/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:29:52 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/08/08 15:52:31 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		go_do_this_2_1(t_lem_in *a)
{
	a->turn++;
	a->cb = 0;
	go_do_this_5(a);
	mlx_hook(a->v->win_ptr, 2, 2, key_press, a);
	mlx_hook(a->v->win_ptr, 17, 17, say_good_buy, a);
}

void		go_do_this_2(t_lem_in *a, int i, int j)
{
	while (a->cc)
	{
		i = 0;
		while (i < a->s_ants && a->turn == a->step_ants[i][0])
		{
			j = 0;
			while (a->step_ants[i][2]
					!= a->w_run->ways[a->step_ants[i][1]]->way[j])
				j++;
			a->step_ants[i][0]++;
			if (a->w_run->ways[a->step_ants[i][1]]->way[j] != a->size_r - 1)
			{
				go_do_this_3(a, i, j);
				if (a->step_ants[i][2] == a->size_r - 1)
					a->cc--;
				ft_printf("L%i-", i);
				ft_printf("[%s] ", a->rooms[a->step_ants[i][2]]->name);
			}
			i++;
		}
		go_do_this_2_1(a);
	}
	go_do_this_2_2(a);
	mlx_loop(a->v->mlx_ptr);
}

int			go_do_this(t_lem_in *a)
{
	a->v->ca = 0;
	mlx_put_image_to_window(a->v->mlx_ptr, a->v->win_ptr,
			a->v->img_ptr_m, 0, 0);
	while (a->v->ca < a->s_ants)
	{
		mlx_put_image_to_window(a->v->mlx_ptr, a->v->win_ptr,
				a->v->img_ptr_a, a->v->ants[a->v->ca][0],
				a->v->ants[a->v->ca][1]);
		a->v->ca++;
	}
	a->cc = a->s_ants;
	go_do_this_2(a, 0, 0);
	return (0);
}

void		go_move_this(t_lem_in *a)
{
	mlx_loop_hook(a->v->mlx_ptr, go_do_this, a);
	mlx_hook(a->v->win_ptr, 2, 2, key_press, a);
	mlx_hook(a->v->win_ptr, 17, 17, say_good_buy, a);
	mlx_loop(a->v->mlx_ptr);
}

void		visualisation_2(t_lem_in *a)
{
	while (a->v->ca < a->s_ants)
	{
		a->v->ants[a->v->ca] = (int *)malloc(sizeof(int) * 6);
		a->v->ants[a->v->ca][0] = a->v->rooms[0][0] - 2;
		a->v->ants[a->v->ca][1] = a->v->rooms[0][1] - 2;
		a->v->ants[a->v->ca][2] = a->v->rooms[0][0] - 2;
		a->v->ants[a->v->ca][3] = a->v->rooms[0][1] - 2;
		a->v->ca++;
	}
	a->ca = 0;
	while (a->ca < a->v->w_x * a->v->w_z)
	{
		*(int *)(a->v->img_adr_m + a->ca * 4) = 0x262523;
		a->ca++;
	}
	a->ca = 0;
	while (a->ca < a->s_rooms - 1)
		put_ways(a);
	put_rooms_v(a);
	get_ants_image(a, 0, 0);
	mlx_put_image_to_window(a->v->mlx_ptr, a->v->win_ptr,
			a->v->img_ptr_m, 0, 0);
	go_move_this(a);
}
