/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:30:53 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/08/08 16:19:49 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lem_exit(int i, t_lem_in *a)
{
	if (a->fm)
	{
		system("pkill afplay");
		a->status = pthread_join(a->thread, (void**)&a->status_addr);
	}
	exit(i);
}

void			*music_power(void *lol)
{
	system("afplay ./src/links_2_3_4.wav &");
	return (lol);
}

void			check_flags(char **av, t_lem_in *a, int i, int j)
{
	void		*lol;

	i = ft_strlen(av[1]);
	lol = NULL;
	if (i < 2 || i > 6 || av[1][0] != '-')
		lem_exit(ft_printf("Invalid arguments\n"), a);
	while (j < i)
	{
		if (av[1][j] == 'w')
			a->fw = 1;
		if (av[1][j] == 'c')
			a->fc = 1;
		if (av[1][j] == 'v')
			a->fv = 1;
		if (av[1][j] == 'p')
			a->fp = 1;
		if (av[1][j] == 'm')
		{
			a->fm = 1;
			a->status = pthread_create(&a->thread, NULL, music_power, lol);
		}
		j++;
	}
	if ((a->fw + a->fc + a->fv + 1 + a->fp + a->fm) != i)
		lem_exit(ft_printf("Invalid arguments\n"), a);
}

void			functions(t_lem_in *a)
{
	add_cells(a, 0, 0);
	finding_the_way(a, 0);
	found_more_ways(a, 0, 0);
	if (a->fp)
		ft_printf("\n\n");
	step_ants(a, a->w_run->n_way, 0, 0);
	if (a->fc)
		ft_printf("\nSteps: %i\n", a->turn - 1);
}

int				main(int ac, char **av)
{
	t_lem_in	*a;

	if (!(a = (t_lem_in *)malloc(sizeof(t_lem_in))))
	{
		ft_putendl("Memory not worcking\n");
		return (0);
	}
	a->fw = 0;
	a->fc = 0;
	a->fv = 0;
	a->fp = 0;
	a->fm = 0;
	if (ac > 2)
		return (ft_printf("Invalid arguments\n"));
	if (ac == 2)
		check_flags(av, a, 0, 1);
	functions(a);
	lem_exit(0, a);
	return (0);
}
