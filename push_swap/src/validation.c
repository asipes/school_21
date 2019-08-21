/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:18:15 by asipes            #+#    #+#             */
/*   Updated: 2019/07/21 12:17:45 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chek_valid(t_push *ds)
{
	ds->i = 0;
	if (ft_isdigit(ds->str[0]) || ds->str[0] == 9 || ds->str[0] == 13 ||
		ds->str[0] == 32 || ds->str[0] == ',' ||
		((ds->str[0] == '+' || ds->str[0] == '-') && ft_isdigit(ds->str[1])))
		ds->i++;
	while ((ds->str[ds->i]) && (ft_isdigit(ds->str[ds->i]) ||
		ds->str[ds->i] == 9 || ds->str[ds->i] == 13 ||
		ds->str[ds->i] == 32 || ds->str[ds->i] == ',' ||
		((ds->str[ds->i] == '+' || ds->str[ds->i] == '-') &&
		(ft_isdigit(ds->str[ds->i + 1]) && !ft_isdigit(ds->str[ds->i - 1])))))
		ds->i++;
	if (ds->str[ds->i] != '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	add_begin_cell(ds);
}

void	check_equally(t_push *ds)
{
	ds->i = 1;
	while (ds->i <= ds->size_a)
	{
		if (ds->this_swap && ds->size_e < 2)
		{
			exit(0);
		}
		if (ds->extra_stack[ds->i - 1] == ds->extra_stack[ds->i])
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		ds->i++;
	}
}

int		check_finish(t_push *ds)
{
	ds->i = 1;
	ds->run = ds->a_beg;
	while (ds->i < ds->size_a)
	{
		if (ds->run->ord != ds->i)
			return (0);
		ds->i++;
		RUN_NEXT;
	}
	return (1);
}
