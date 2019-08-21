/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 00:59:42 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/08/08 16:30:22 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_start(t_lem_in *a, int ord)
{
	a->run = a->c_beg;
	while (a->run->flag != 3)
		RUN;
	a->r_beg = (t_rooms *)malloc(sizeof(t_rooms));
	a->r_beg->name = ft_strnew(ft_strlen(a->run->name));
	a->r_beg->name = ft_strcpy(a->r_beg->name, a->run->name);
	a->r_beg->ord = ord;
	ord++;
	a->r_beg->x_pos = li_atoi(a->run->x_pos, 0, a, 0);
	a->r_beg->y_pos = li_atoi(a->run->y_pos, 0, a, 0);
	a->r_beg->next = NULL;
	a->r_beg->p_room = NULL;
	a->r_beg->e_room = NULL;
	a->r_beg->numb = -1;
	a->run->flag = 2;
	put_rooms(a, ord);
}

void	put_rooms(t_lem_in *a, int ord)
{
	a->run = a->c_beg;
	a->run_r = a->r_beg;
	while (a->run->flag != 6 && a->run->name)
	{
		if (a->run->flag == 5)
		{
			a->run_r->next = (t_rooms *)malloc(sizeof(t_rooms));
			a->run_r = a->run_r->next;
			a->run_r->name = ft_strnew(ft_strlen(a->run->name));
			a->run_r->name = ft_strcpy(a->run_r->name, a->run->name);
			a->run_r->ord = ord;
			ord++;
			a->run_r->x_pos = li_atoi(a->run->x_pos, 0, a, 0);
			a->run_r->y_pos = li_atoi(a->run->y_pos, 0, a, 0);
			a->run_r->next = NULL;
			a->run_r->p_room = NULL;
			a->run_r->e_room = NULL;
			a->run_r->numb = -1;
			a->run->flag = 2;
		}
		RUN;
	}
	put_end(a, ord);
}

void	put_end(t_lem_in *a, int ord)
{
	a->run = a->c_beg;
	while (a->run->flag != 4)
		RUN;
	a->run_r->next = (t_rooms *)malloc(sizeof(t_rooms));
	a->run_r = a->run_r->next;
	a->run_r->name = ft_strnew(ft_strlen(a->run->name));
	a->run_r->name = ft_strcpy(a->run_r->name, a->run->name);
	a->run_r->ord = ord;
	ord++;
	a->run_r->x_pos = li_atoi(a->run->x_pos, 0, a, 0);
	a->run_r->y_pos = li_atoi(a->run->y_pos, 0, a, 0);
	a->run_r->next = NULL;
	a->run_r->p_room = NULL;
	a->run->flag = 2;
	a->size_r = ord;
	if (check_valid_connect(a, 0, 0))
		lem_exit(ft_printf("Invalid connect\n"), a);
	add_rooms_arr(a);
	add_matrix_connect(a, 0, 0);
}

void	add_rooms_arr(t_lem_in *a)
{
	a->rooms = (t_rooms**)malloc(sizeof(t_rooms *) * a->size_r);
	a->run_r = a->r_beg;
	while (a->run_r)
	{
		a->rooms[a->run_r->ord] = a->run_r;
		RUN_R;
	}
}

void	add_matrix_connect(t_lem_in *a, int i, int j)
{
	a->a_conn = (int **)malloc(sizeof(int *) * a->size_r);
	while (i < a->size_r)
	{
		if (!(a->a_conn[i] = (int *)malloc(sizeof(int) * a->size_r)))
			lem_exit(ft_printf("no_memory"), a);
		i++;
	}
	i = 0;
	j += 0;
	while (i < a->size_r)
	{
		j = 0;
		while (j < a->size_r)
		{
			a->a_conn[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	put_matrix(a, 0);
}
