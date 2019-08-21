/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   by.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:08:51 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:30:43 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		key_press(int key, t_push *ds)
{
	if (key == 53)
	{
		ds->vis = 0;
		mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
		initialize(ds);
	}
	if (key == 49)
		sleep(1);
	ds->i = ds->i;
	return (0);
}

int		by_by(t_push *ds)
{
	if (check_finish(ds) && ds->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(0);
	return (0);
}

void	by(t_push *ds)
{
	ft_printf("Error\n");
	exit(0);
	ds->i = ds->i;
}
