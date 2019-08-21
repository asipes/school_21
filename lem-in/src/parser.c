/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:20:32 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/08/08 16:25:22 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_cells(t_lem_in *a, int fd, int i)
{
	a->sv = 0;
	add_cells_1(a);
	while ((a->gnl = get_next_line(fd, &a->run->str)) == 1 &&
			ft_strlen(a->run->str))
	{
		i++;
		ft_printf("%s\n", a->run->str);
		a->run->next = (t_cells *)malloc(sizeof(t_cells));
		a->tmp = a->run;
		RUN;
		add_cells_2(a);
	}
	ft_printf("\n");
	add_cells_3(a, i);
	while (a->c_l < a->size_sc)
	{
		check_valid(a, 0, 0);
		RUN;
		a->c_l++;
	}
	a->c_l = 0;
	a->run = a->c_beg;
	check_invalid_str(a, 0, 0, 0);
	val_ants(a);
}

void	add_cells_1(t_lem_in *a)
{
	a->c_beg = (t_cells *)malloc(sizeof(t_cells));
	a->size_sc = 1;
	a->c_beg->next = NULL;
	a->run = a->c_beg;
	a->run->flag = 0;
	a->gnl_c = 0;
}

void	add_cells_2(t_lem_in *a)
{
	a->run->flag = 0;
	a->run->next = NULL;
	a->run->str = NULL;
	a->size_sc++;
	a->gnl_c++;
}

void	add_cells_3(t_lem_in *a, int i)
{
	if (a->gnl_c < 6)
		lem_exit(ft_printf("Empty fail\n"), a);
	free(a->run);
	a->tmp->next = NULL;
	a->size_sc--;
	if (!i)
		lem_exit(ft_printf("Invalid arguments\n"), a);
	a->arc = -1;
	a->run = a->c_beg;
	a->c_l = 0;
}
