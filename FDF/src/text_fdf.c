/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:44:49 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/01 11:49:02 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		text_fdf(t_fdfstr *a, int j, char *str)
{
	mlx_string_put(a->mlx_ptr, a->win_ptr, j, a->c_c, a->c_b, str);
}

void		t_fdf(t_fdfstr *a, char *str, char *stl)
{
	mlx_string_put(a->mlx_ptr, a->win_ptr, 20, a->c_c, 255 << 16, str);
	mlx_string_put(a->mlx_ptr, a->win_ptr, 170, a->c_c, 255 << 8, stl);
}

void		t1_fdf(t_fdfstr *a, char *str, char *stl)
{
	mlx_string_put(a->mlx_ptr, a->win_ptr, 20, a->c_c, 255 << 16, str);
	mlx_string_put(a->mlx_ptr, a->win_ptr, 60, a->c_c, 255 << 8, stl);
}
