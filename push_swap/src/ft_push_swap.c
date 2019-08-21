/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:11:20 by asipes            #+#    #+#             */
/*   Updated: 2019/07/21 12:16:31 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_go(t_push *ds, int argc, char **argv)
{
	pointer_on_null(ds);
	ds->this_swap = 1;
	ds->str = ft_strnew(1);
	while (ds->i++ < argc - 1)
		tracing(ds, argv[ds->i]);
	chek_valid(ds);
	add_extra_stack(ds);
	check_equally(ds);
	put_order(ds);
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
	push_go(ds, argc, argv);
	if (ds->size_a > 5)
		begin_sort(ds);
	else
		mini_sort(ds);
	while (!(check_finish(ds)) && ds->size_e > 5)
		sort_second(ds);
	check_answer(ds);
	return (0);
}
