/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_anton_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:40:40 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/01 13:32:13 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			test_anton_fdf(t_fdfstr *a)
{
	a->mlx_ptr = mlx_init();
	go_go_to_start_fdf(a);
	if (!(a->win_ptr = mlx_new_window(a->mlx_ptr, a->size_win_x, a->size_win_y,
			"FDF")) || !(a->im2_ptr = mlx_new_image(a->mlx_ptr, a->size_win_x,
			a->size_win_y)) || !(a->img_ptr = mlx_get_data_addr(a->im2_ptr,
			&a->bpp, &a->stride, &a->endian)))
		return (1);
	a->bpp /= 8;
	paint_map_fdf(a);
	mlx_hook(a->win_ptr, 2, 2, key_press_fdf, a);
	mlx_hook(a->win_ptr, 17, 17, say_good_buy_fdf, a);
	mlx_hook(a->win_ptr, 4, 4, mouse_press_fdf, a);
	mlx_hook(a->win_ptr, 5, 5, mouse_dont_press_fdf, a);
	mlx_hook(a->win_ptr, 6, 6, mouse_go_fdf, a);
	mlx_loop(a->mlx_ptr);
	return (0);
}
