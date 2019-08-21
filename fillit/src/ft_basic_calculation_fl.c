/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_calculation_fl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:19:19 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/01/15 15:35:21 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_norm_fl(char ***s, int *c, int **a)
{
	if (ft_isalpha(s[c[2]][2][0]) && (c[3] + 2) < c[1]
			&& s[c[0]][c[3] + 2][c[4]] == '.')
		s[c[0]][c[3] + 2][c[4]] = s[c[2]][2][0];
	if (ft_isalpha(s[c[2]][3][0]) && (c[3] + 3) < c[1]
			&& s[c[0]][c[3] + 3][c[4]] == '.')
		s[c[0]][c[3] + 3][c[4]] = s[c[2]][3][0];
	if (ft_isalpha(s[c[2]][1][1]) && (c[3] + 1) < c[1] && (c[4] + 1) < c[1]
			&& s[c[0]][c[3] + 1][c[4] + 1] == '.')
		s[c[0]][c[3] + 1][c[4] + 1] = s[c[2]][1][1];
	if (ft_isalpha(s[c[2]][2][1]) && (c[3] + 2) < c[1] && (c[4] + 1) < c[1]
			&& s[c[0]][c[3] + 2][c[4] + 1] == '.')
		s[c[0]][c[3] + 2][c[4] + 1] = s[c[2]][2][1];
	if (ft_isalpha(s[c[2]][1][2]) && (c[3] + 1) < c[1] && (c[4] + 2) < c[1]
			&& s[c[0]][c[3] + 1][c[4] + 2] == '.')
		s[c[0]][c[3] + 1][c[4] + 2] = s[c[2]][1][2];
	a[c[2]][0] = c[3];
	a[c[2]][1] = c[4];
	c[2]++;
	c[3] = 0;
	c[4] = 0;
	return (1);
}

int			ft_hard_fl(char ***s, int *c, int **a)
{
	if (ft_isalpha(s[c[2]][2][1]) && (c[3] + 2) < c[1] && (c[4] + 1) < c[1]
			&& s[c[0]][c[3] + 2][c[4] + 1] == '.')
		c[5]++;
	if (ft_isalpha(s[c[2]][1][2]) && (c[3] + 1) < c[1] && (c[4] + 2) < c[1]
			&& s[c[0]][c[3] + 1][c[4] + 2] == '.')
		c[5]++;
	if (c[5] < 4)
		return (0);
	if (ft_isalpha(s[c[2]][0][0]) && s[c[0]][c[3]][c[4]] == '.')
		s[c[0]][c[3]][c[4]] = s[c[2]][0][0];
	if (ft_isalpha(s[c[2]][0][1]) && (c[4] + 1) < c[1]
			&& s[c[0]][c[3]][c[4] + 1] == '.')
		s[c[0]][c[3]][c[4] + 1] = s[c[2]][0][1];
	if (ft_isalpha(s[c[2]][0][2]) && (c[4] + 2) < c[1]
			&& s[c[0]][c[3]][c[4] + 2] == '.')
		s[c[0]][c[3]][c[4] + 2] = s[c[2]][0][2];
	if (ft_isalpha(s[c[2]][0][3]) && (c[4] + 3) < c[1]
			&& s[c[0]][c[3]][c[4] + 3] == '.')
		s[c[0]][c[3]][c[4] + 3] = s[c[2]][0][3];
	if (ft_isalpha(s[c[2]][1][0]) && (c[3] + 1) < c[1]
			&& s[c[0]][c[3] + 1][c[4]] == '.')
		s[c[0]][c[3] + 1][c[4]] = s[c[2]][1][0];
	return (ft_norm_fl(s, c, a));
}

int			ft_eazy_fl(char ***s, int *c, int **a)
{
	c[5] = 0;
	if (ft_isalpha(s[c[2]][0][0]) && s[c[0]][c[3]][c[4]] == '.')
		c[5]++;
	if (ft_isalpha(s[c[2]][0][1]) && (c[4] + 1) < c[1]
			&& s[c[0]][c[3]][c[4] + 1] == '.')
		c[5]++;
	if (ft_isalpha(s[c[2]][0][2]) && (c[4] + 2) < c[1]
			&& s[c[0]][c[3]][c[4] + 2] == '.')
		c[5]++;
	if (ft_isalpha(s[c[2]][0][3]) && (c[4] + 3) < c[1]
			&& s[c[0]][c[3]][c[4] + 3] == '.')
		c[5]++;
	if (ft_isalpha(s[c[2]][1][0]) && (c[3] + 1) < c[1]
			&& s[c[0]][c[3] + 1][c[4]] == '.')
		c[5]++;
	if (ft_isalpha(s[c[2]][2][0]) && (c[3] + 2) < c[1]
			&& s[c[0]][c[3] + 2][c[4]] == '.')
		c[5]++;
	if (ft_isalpha(s[c[2]][3][0]) && (c[3] + 3) < c[1]
			&& s[c[0]][c[3] + 3][c[4]] == '.')
		c[5]++;
	if (ft_isalpha(s[c[2]][1][1]) && (c[3] + 1) < c[1] && (c[4] + 1) < c[1]
			&& s[c[0]][c[3] + 1][c[4] + 1] == '.')
		c[5]++;
	return (ft_hard_fl(s, c, a));
}

int			ft_new_mem_fl(char ***sup, int *c)
{
	if (sup[c[0]])
	{
		c[8] = 0;
		while (sup[c[0]][c[8]])
		{
			free(sup[c[0]][c[8]]);
			c[8]++;
		}
		free(sup[c[0]]);
	}
	if (!(sup[c[0]] = (char **)malloc(sizeof(char *) * c[1] + 1)))
		return (1);
	c[8] = 0;
	while (c[8] < c[1])
	{
		if (!(sup[c[0]][c[8]] = ft_strnew(c[1])))
			return (1);
		ft_memset(sup[c[0]][c[8]], '.', c[1]);
		c[8]++;
	}
	sup[c[0]][c[1]] = NULL;
	return (0);
}

int			ft_basic_calculation_fl(int *c, char ***sup, int **a)
{
	ft_bzero(&c[2], sizeof(int) * 8);
	while (c[3] < c[1] && c[2] < c[0])
	{
		if ((!(c[3]) && !(c[4]) && !(c[2]) && ft_new_mem_fl(sup, c)))
			return (0);
		if (c[4] < c[1] && c[2] < c[0] && !(ft_eazy_fl(sup, c, a)))
			c[4]++;
		if (c[2] == c[0])
			return (1);
		if (c[4] == c[1])
		{
			c[4] = 0;
			c[3]++;
		}
		ft_bas_calc_extra_lines_fl(c, sup, a);
	}
	return (1);
}
