/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:11:58 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 20:55:06 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualization(t_push *ds)
{
	ds->mlx_ptr = mlx_init();
	window_size(ds);
	if (ds->pix)
	{
		ds->win_ptr = mlx_new_window(ds->mlx_ptr, ds->s_x, ds->s_y, "Checker");
		ds->img_ptr = mlx_new_image(ds->mlx_ptr, ds->s_x, ds->s_y);
		ds->img_adr = mlx_get_data_addr(ds->img_ptr, &ds->bpp, &ds->stride,
						&ds->endian);
		ds->bpp /= 8;
		print_stack(ds);
		mlx_loop_hook(ds->mlx_ptr, go_check, ds);
		mlx_hook(ds->win_ptr, 2, 2, key_press, ds);
		mlx_hook(ds->win_ptr, 17, 17, by_by, ds);
		mlx_loop(ds->mlx_ptr);
	}
	else
	{
		ds->vis = 0;
		initialize(ds);
	}
}

void	window_size(t_push *ds)
{
	if (ds->size_a >= 1000)
		ds->pix = 1;
	else if (ds->size_a >= 400)
		ds->pix = 2;
	else if (ds->size_a >= 200)
		ds->pix = 4;
	else if (ds->size_a >= 90)
		ds->pix = 8;
	else
		ds->pix = 32;
	if (ds->size_a > 1300)
		ds->pix = 0;
	ds->s_x = ds->pix * ds->size_a * 2;
	ds->s_y = ds->pix * ds->size_a;
}

void	initialize(t_push *ds)
{
	ds->i = 0;
	if (ds->vis)
		visualization(ds);
	else
	{
		while (1)
			go_check(ds);
	}
}

int		main(int argc, char **argv)
{
	t_push *ds;

	if (argc < 2)
		return (0);
	if (!(ds = (t_push *)malloc(sizeof(t_push))))
		return (ft_printf("Error\n"));
	if (!(ds->a_beg = (t_cell *)malloc(sizeof(t_cell))))
		return (ft_printf("Error\n"));
	pointer_on_null(ds);
	ds->str = ft_strnew(1);
	if (ft_strlen(argv[1]) == 2 && argv[1][0] == '-' && argv[1][1] == 'v')
	{
		ds->i++;
		ds->vis = 1;
	}
	while (ds->i++ < argc - 1)
		tracing(ds, argv[ds->i]);
	chek_valid(ds);
	add_extra_stack(ds);
	check_equally(ds);
	put_order(ds);
	initialize(ds);
}
