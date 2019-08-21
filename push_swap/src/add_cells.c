/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cells.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:00:01 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 20:53:06 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_cells(t_push *ds)
{
	if (!(ds->temp = (t_cell *)malloc(sizeof(t_push))))
	{
		ft_printf("Error\n");
		exit(0);
	}
	ds->temp->next = ds->a_beg;
	ds->temp->prev = ds->run;
	ds->a_beg->prev = ds->temp;
	ds->run->next = ds->temp;
	ds->run = ds->run->next;
	ds->run->ord = 0;
	ds->run->flag = 0;
	ds->size_a++;
	ds->temp = NULL;
}

void	add_begin_cell(t_push *ds)
{
	null_cell(ds);
	ds->i = ds->j;
	while (ds->str[ds->i])
	{
		if (ft_isdigit(ds->str[ds->i]) || ds->str[ds->i] == '-' ||
				ds->str[ds->i] == '+')
		{
			ds->j = ds->i;
			while (ft_isdigit(ds->str[ds->i]) || ds->str[ds->i] == '-' ||
					ds->str[ds->i] == '+')
				ds->i++;
			add_cells(ds);
			ds->run->val = ps_atoi(ds, 0, 1);
		}
		ds->i++;
	}
	ds->size_e = ds->size_a;
	ft_strdel(&ds->str);
	ds->str = ft_strnew(1);
}

void	null_cell(t_push *ds)
{
	ds->j = 0;
	ds->a_beg->val = ps_atoi(ds, 0, 1);
	ds->size_a++;
	ds->run = ds->a_beg;
	ds->run->ord = 0;
	ds->run->flag = 0;
}
