/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bas_calc_extra_lines_fl.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 00:16:47 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/01/15 15:35:56 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_bas_calc_extra_lines_fl(int *c, char ***sup, int **a)
{
	if (c[3] == c[1] && c[2] < c[0])
	{
		if (c[2])
		{
			c[2]--;
			ft_del_mino_fl(sup, c);
		}
		a[c[2]][1]++;
		c[4] = a[c[2]][1];
		c[3] = a[c[2]][0];
	}
	if (a[c[2]][1] == c[1])
	{
		a[c[2]][0]++;
		a[c[2]][1] = 0;
	}
	if ((c[2] == 0 && a[c[2]][0] == c[1]))
	{
		ft_bzero(&c[2], sizeof(int) * 7);
		c[1]++;
	}
}

int			**ft_new_arr_fl(int **swap, int *c)
{
	ft_bzero(&c[3], sizeof(int) * 7);
	while (c[9] < c[0])
	{
		if (!(swap[c[9]] = (int *)malloc(sizeof(int) * 2)))
		{
			while (c[8] < c[9])
			{
				free(swap[c[8]]);
				c[8]++;
			}
			free(swap);
			return (NULL);
		}
		swap[c[9]][0] = 0;
		swap[c[9]][1] = 0;
		c[9]++;
	}
	ft_bzero(&c[3], sizeof(int) * 7);
	return (swap);
}

int			ft_free_swap_fl(int **swap, int *c, char **line, char ***s)
{
	c[9] = 0;
	while (c[9] < c[0])
	{
		free(swap[c[9]]);
		c[9]++;
	}
	free(swap);
	return (ft_byby_fl(line, c, s));
}

void		ft_del_mino_fl(char ***s, int *c)
{
	int		i;
	int		j;

	i = 0;
	while (i < c[1])
	{
		j = 0;
		while (j < c[1])
		{
			if (s[c[0]][i][j] == ('A' + c[2]))
				s[c[0]][i][j] = '.';
			j++;
		}
		i++;
	}
}
