/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:13:40 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:16:57 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		go_check(t_push *ds)
{
	ds->gnl = get_next_line(0, &ds->gnl_str);
	if (ds->gnl != 1)
		by_by(ds);
	if (ft_strlen(ds->gnl_str) == 2)
		go_check_1(ds);
	else if (ft_strlen(ds->gnl_str) == 3)
		go_check_2(ds);
	else
		by(ds);
	ft_strdel(&ds->gnl_str);
	if (ds->vis)
	{
		print_stack(ds);
	}
	return (0);
}

void	go_check_1(t_push *ds)
{
	if (ds->gnl_str[0] == 's' && ds->gnl_str[1] == 'a')
		sa(ds);
	else if (ds->gnl_str[0] == 's' && ds->gnl_str[1] == 'b')
		sb(ds);
	else if (ds->gnl_str[0] == 's' && ds->gnl_str[1] == 's')
		ss(ds);
	else if (ds->gnl_str[0] == 'p' && ds->gnl_str[1] == 'a')
		pa(ds);
	else if (ds->gnl_str[0] == 'p' && ds->gnl_str[1] == 'b')
		pb(ds);
	else if (ds->gnl_str[0] == 'r' && ds->gnl_str[1] == 'a')
		ra(ds);
	else if (ds->gnl_str[0] == 'r' && ds->gnl_str[1] == 'b')
		rb(ds);
	else if (ds->gnl_str[0] == 'r' && ds->gnl_str[1] == 'r')
		rr(ds);
	else
		by(ds);
}

void	go_check_2(t_push *ds)
{
	if (ds->gnl_str[0] == 'r' && ds->gnl_str[1] == 'r'
							&& ds->gnl_str[2] == 'a')
		rra(ds);
	else if (ds->gnl_str[0] == 'r' && ds->gnl_str[1] == 'r'
								&& ds->gnl_str[2] == 'b')
		rrb(ds);
	else if (ds->gnl_str[0] == 'r' && ds->gnl_str[1] == 'r'
								&& ds->gnl_str[2] == 'r')
		rrr(ds);
	else
		by(ds);
}

void	print_stack(t_push *ds)
{
	ft_bzero(ds->img_adr, ds->s_y * ds->s_x * sizeof(int));
	ds->ca = 0;
	ds->run = ds->a_beg;
	ds->temp = ds->b_beg;
	while (ds->ca < ds->size_a || ds->ca < ds->size_b)
	{
		get_image(ds, 0, 0);
		ds->ca++;
		if (ds->size_a > ds->ca)
			RUN_NEXT;
		if (ds->size_b > ds->ca)
			RUN_NEXT_B;
	}
	mlx_put_image_to_window(ds->mlx_ptr, ds->win_ptr, ds->img_ptr, 0, 0);
}

void	get_image(t_push *ds, int i, int j)
{
	ds->cb = 0;
	while (ds->cb < ds->pix)
	{
		if (ds->size_a)
			i = ds->run->ord * ds->pix;
		if (ds->size_a < ds->ca)
			i = 0;
		if (ds->size_b)
			j = ds->temp->ord * ds->pix;
		if (ds->size_b < ds->ca)
			j = 0;
		while (i)
		{
			*(int *)(ds->img_adr + ((i + (ds->ca * ds->pix + ds->cb)
			* ds->s_x) * ds->bpp)) = 0xeac30f;
			i--;
		}
		while (j)
		{
			*(int *)(ds->img_adr + ((-j + (ds->ca * ds->pix + ds->cb + 1)
			* ds->s_x) * ds->bpp)) = 0x0f71ea;
			j--;
		}
		ds->cb++;
	}
}
