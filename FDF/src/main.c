/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 22:35:47 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/27 17:24:24 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_fdfstr		*a;

	if (!(a = (t_fdfstr *)malloc(sizeof(t_fdfstr))))
	{
		ft_putendl("Memory not worcking!\n");
		return (0);
	}
	if (ac != 2 && ft_printf("Usage : ./fdf <filename> [ case_size z_size ]\n"))
		exit(1);
	if (((a->fd = open(av[1], O_RDONLY)) < 0) &&
			ft_printf("No file %s\n", av[1]))
		exit(1);
	if (read_map_fdf(a))
	{
		ft_putendl("Found wrong line length. Exiting.");
		exit(1);
	}
	exit(0);
}
