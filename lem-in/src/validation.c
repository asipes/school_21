/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:10:02 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/08/08 14:00:40 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_valid(t_lem_in *a, int len, int i)
{
	len = ft_strlen(a->run->str);
	if (len > 0 && a->run->str[i] == 'L')
		lem_exit(ft_printf("Is L\n"), a);
	if (len > 0 && a->run->str[0] == '#')
	{
		if (ft_strequ(a->run->str, "##start"))
			a->run->flag = 3;
		else if (ft_strequ(a->run->str, "##end"))
			a->run->flag = 4;
		else
			a->run->flag = 2;
	}
	if (len > 0 && ft_isdigit(a->run->str[i]))
	{
		while (ft_isdigit(a->run->str[i]))
			i++;
		if (len == i)
			a->run->flag = 1;
	}
	check_room(a, len, 0, 0);
	check_way(a, len, 0, 0);
}

void	check_invalid_str(t_lem_in *a, int ch_pos, int start, int end)
{
	while (a->c_l < a->size_sc)
	{
		if (a->run->flag == 0)
			lem_exit(ft_printf("invalid str\n"), a);
		else if (a->run->flag == 1 && ch_pos == 0)
			ch_pos++;
		else if (a->run->flag == 1 && ch_pos > 0)
			lem_exit(ft_printf("double_ants\n"), a);
		else if (a->run->flag > 2 && ch_pos == 0)
			lem_exit(ft_printf("missing ants\n"), a);
		else if ((a->run->flag > 2 && a->run->flag < 6) && ch_pos == 1)
			ch_pos++;
		else if (a->run->flag == 6 && ch_pos == 1)
			lem_exit(ft_printf("missing rooms\n"), a);
		else if (a->run->flag == 6 && ch_pos == 2)
			ch_pos++;
		else if ((a->run->flag > 2 && a->run->flag < 6) && ch_pos == 3)
			lem_exit(ft_printf("invalid order\n"), a);
		if (a->run->flag == 3)
			start = check_invalid_str_s(start, a);
		if (a->run->flag == 4)
			end = check_invalid_str_e(end, a);
		RUN;
		a->c_l++;
	}
}

int		check_invalid_str_s(int start, t_lem_in *a)
{
	if (start == 0)
		start++;
	else if (start > 0)
		lem_exit(ft_printf("double start\n"), a);
	return (start);
}

int		check_invalid_str_e(int end, t_lem_in *a)
{
	if (end == 0)
		end++;
	else if (end > 0)
		lem_exit(ft_printf("double end\n"), a);
	return (end);
}
