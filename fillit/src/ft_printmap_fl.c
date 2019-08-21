/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap_fl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:27:53 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/01/13 00:41:22 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_printmap_fl(char ***s, char **line, int *c, int **swap)
{
	c[3] = 0;
	if (!(s))
	{
		while (line[c[3]])
		{
			ft_putendl(line[c[3]]);
			free(line[c[3]]);
			c[3]++;
		}
		free(line);
		free(c);
	}
	else
	{
		while (s[c[0]][c[3]])
		{
			ft_putendl(s[c[0]][c[3]]);
			c[3]++;
		}
		ft_free_swap_fl(swap, c, line, s);
	}
	return (1);
}
