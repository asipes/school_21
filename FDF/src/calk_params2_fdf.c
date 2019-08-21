/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calk_params2_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:38:47 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/27 17:21:53 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_digit_fdf(t_fdfstr *a, t_fdfread *newl)
{
	if (newl->str[a->c_a] != '	')
	{
		a->arr[a->c_par][2] = ft_atoi(&(newl->str[a->c_a]));
		a->arr[a->c_par][0] = a->c_x;
		a->arr[a->c_par][1] = a->c_y;
		a->c_x++;
		a->c_par++;
		while (newl->str[a->c_a] && newl->str[a->c_a] != ' ' &&
				newl->str[a->c_a] != '	' && newl->str[a->c_a] != ',')
			a->c_a++;
		if (newl->str[a->c_a] == ',')
		{
			a->c_a++;
			check_hex_fdf(a, newl);
		}
	}
	while (newl->str[a->c_a] && newl->str[a->c_a] != ' ')
		a->c_a++;
}

int		read_param_fdf(t_fdfstr *a, t_fdfread *newl)
{
	while (newl->str[a->c_a] && a->c_x < a->c_stl)
		if (newl->str[a->c_a] == ' ')
			a->c_a++;
		else
			find_digit_fdf(a, newl);
	if (a->c_x < a->c_stl)
		return (1);
	a->c_y++;
	return (0);
}

int		read_strukt_fdf(t_fdfstr *a, t_fdfread *newl)
{
	while (a->c_a < a->c_par)
	{
		if (!(a->arr[a->c_a] = (int *)malloc(sizeof(int) * 7)))
			return (1);
		a->arr[a->c_a][3] = -1;
		a->c_a++;
	}
	a->c_y = 0;
	a->c_par = 0;
	while (newl->next)
	{
		a->c_a = 0;
		a->c_x = 0;
		if (read_param_fdf(a, newl))
			return (1);
		newl = newl->next;
	}
	return (clean_list_fdf(a, newl));
}

int		calk_params2_fdf(t_fdfstr *a, t_fdfread *newl)
{
	a->c_a = 0;
	a->c_stl = 0;
	while (newl->str[a->c_a])
	{
		if (newl->str[a->c_a] == ' ')
			a->c_a++;
		else
		{
			if (newl->str[a->c_a] != '	')
				a->c_stl++;
			while (newl->str[a->c_a] && newl->str[a->c_a] != ' ')
				a->c_a++;
		}
	}
	a->c_par = a->c_stl * a->c_str;
	if (!(a->arr = (int **)malloc(sizeof(int *) * a->c_par)))
		return (1);
	a->c_a = 0;
	return (read_strukt_fdf(a, newl));
}
