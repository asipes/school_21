/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:48:06 by asipes            #+#    #+#             */
/*   Updated: 2019/08/08 13:54:13 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_room(t_lem_in *a, int len, int i, int pos)
{
	while (a->run->str[i] && a->run->str[i] != ' ')
		i++;
	pos = i;
	if (len > i && a->run->str[i] == ' ' && ft_isdigit(a->run->str[i + 1]))
	{
		a->run->x_pos = &a->run->str[i + 1];
		i++;
		while (a->run->str[i] && ft_isdigit(a->run->str[i]))
			i++;
	}
	else
		return ;
	if (len > i && a->run->str[i] == ' ' && ft_isdigit(a->run->str[i + 1]))
	{
		a->run->y_pos = &a->run->str[i + 1];
		i++;
		while (a->run->str[i] && ft_isdigit(a->run->str[i]))
			i++;
	}
	else
		return ;
	if (len == i)
		check_room_1(a, pos);
}

void	check_room_1(t_lem_in *a, int pos)
{
	a->run->flag = 5;
	a->run->name = ft_strnew(pos);
	a->run->name = ft_strncpy(a->run->name, a->run->str, pos);
}

void	check_way(t_lem_in *a, int len, int i, int pos)
{
	if (len > 0)
		while (a->run->str[i] && (ft_isprint(a->run->str[i])
				&& a->run->str[i] != '-'))
			i++;
	else
		return ;
	pos = i;
	if (len > i && a->run->str[i] == '-')
	{
		i++;
		a->run->tmp = &a->run->str[i];
		while (a->run->str[i] && (ft_isprint(a->run->str[i])
				&& a->run->str[i] != '-'))
			i++;
	}
	else
		return ;
	if (len == i)
	{
		check_way_1(a, pos);
		pos = i - pos;
		a->run->name_sc = ft_strnew(pos);
		a->run->name_sc = ft_strncpy(a->run->name_sc, a->run->tmp, pos);
		a->run->flag = 6;
	}
}

void	check_way_1(t_lem_in *a, int pos)
{
	a->run->name_fc = ft_strnew(pos);
	a->run->name_fc = ft_strncpy(a->run->name_fc, a->run->str, pos);
}
