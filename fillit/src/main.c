/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:20:40 by asipes            #+#    #+#             */
/*   Updated: 2019/01/20 15:20:42 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			main(int ac, char **av)
{
	int		fd;
	char	**line;
	int		*counter;

	if (ac != 2 || !(counter = (int *)malloc(sizeof(int) * 10)))
	{
		ft_putendl("Usage: ./fillit file_name");
		return (0);
	}
	ft_bzero(counter, sizeof(int) * 10);
	fd = open(av[1], O_RDONLY);
	line = (char **)malloc(sizeof(char *) * 140);
	if (ft_emergency_exit_fl(fd, line, counter))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(ft_conversion_fl(line, counter)))
	{
		ft_putendl("Memory error!");
		return (0);
	}
	return (1);
}
