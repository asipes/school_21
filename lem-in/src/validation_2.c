/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:48:06 by asipes            #+#    #+#             */
/*   Updated: 2019/08/08 16:26:34 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	val_ants(t_lem_in *a)
{
	a->run = a->c_beg;
	while (a->run->flag != 1)
		RUN;
	a->s_ants = li_atoi(a->run->str, 0, a, 0);
	a->run->flag = 2;
	valid_rooms_name(a, 0, 0);
}

void	valid_rooms_name(t_lem_in *a, int i, int j)
{
	a->tmp = a->c_beg;
	while (i < a->size_sc)
	{
		j = i + 1;
		if (a->tmp->flag == 5 && a->tmp->next != NULL)
		{
			a->run = a->tmp->next;
			while (j < a->size_sc)
			{
				if (a->run->flag == 5 && ft_strequ(a->tmp->name, a->run->name))
					lem_exit(ft_printf("equal name"), a);
				RUN;
				j++;
			}
		}
		i++;
		a->tmp = a->tmp->next;
	}
	count_rooms(a, 0);
}

void	count_rooms(t_lem_in *a, int i)
{
	a->run = a->c_beg;
	a->size_r = 0;
	while (i < a->size_sc)
	{
		if (a->run->flag == 5)
			a->size_r++;
		RUN;
		i++;
	}
	a->run = a->c_beg;
	initialization_start_and_end(a, 0, 0);
	put_start(a, 0);
}

void	initialization_start_and_end(t_lem_in *a, int i, int flag)
{
	while (i < a->size_sc)
	{
		if (flag == 1 && a->run->flag == 5)
		{
			a->run->flag = 3;
			flag = 0;
		}
		else if (flag == 2 && a->run->flag == 5)
		{
			a->run->flag = 4;
			flag = 0;
		}
		else if (a->run->flag == 3)
		{
			a->run->flag = 2;
			flag = 1;
		}
		else if (a->run->flag == 4)
		{
			a->run->flag = 2;
			flag = 2;
		}
		RUN;
		i++;
	}
}
