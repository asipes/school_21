/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_fl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:19:10 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/01/15 15:08:04 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_byby_fl(char **line, int *c, char ***s)
{
	c[3] = 0;
	if (line)
		while (line[c[3]])
		{
			free(line[c[3]]);
			c[3]++;
		}
	c[3] = 0;
	if (s)
		while (s[c[3]])
		{
			c[4] = 0;
			while (s[c[3]][c[4]])
			{
				free(s[c[3]][c[4]]);
				c[4]++;
			}
			free(s[c[3]]);
			c[3]++;
		}
	if (s)
		free(s);
	free(line);
	free(c);
	return (0);
}

int			ft_basik_conversion_fl(char **line, int *c, char ***s)
{
	while (c[4] < c[1])
	{
		if (!(s[c[3]]))
			if (!(s[c[3]] = (char **)malloc(sizeof(char *) * 5)))
				return (1);
		if (!(s[c[3]][c[4] % 4] = ft_strdup(line[c[4]])))
			return (1);
		c[4]++;
		s[c[3]][4] = NULL;
		c[3] = c[4] / 4;
	}
	s[c[0] + 1] = NULL;
	c[1] = c[2];
	ft_bzero(&c[2], sizeof(int) * 8);
	return (0);
}

void		ft_fear_fl(int *c, char ***s)
{
	if (!ft_isalpha(s[c[3]][0][c[4]]) && !ft_isalpha(s[c[3]][1][c[4]]) &&
			!ft_isalpha(s[c[3]][2][c[4]]) && !ft_isalpha(s[c[3]][3][c[4]]))
	{
		ft_strcpy(&s[c[3]][0][c[4]], &s[c[3]][0][c[4] + 1]);
		ft_strcpy(&s[c[3]][1][c[4]], &s[c[3]][1][c[4] + 1]);
		ft_strcpy(&s[c[3]][2][c[4]], &s[c[3]][2][c[4] + 1]);
		ft_strcpy(&s[c[3]][3][c[4]], &s[c[3]][3][c[4] + 1]);
	}
	if (!ft_isalpha(s[c[3]][c[4]][0]) && !ft_isalpha(s[c[3]][c[4]][1]) &&
			!ft_isalpha(s[c[3]][c[4]][2]) && !ft_isalpha(s[c[3]][c[4]][3]))
	{
		c[5] = c[4];
		while (c[5] < 4)
		{
			if (s[c[3]][c[5] + 1])
				ft_memcpy(s[c[3]][c[5]], s[c[3]][c[5] + 1], 4);
			else
				ft_bzero(s[c[3]][c[5]], sizeof(char) * 4);
			c[5]++;
		}
	}
}

int			ft_del_stars_fl(int *c, char ***s, char **line)
{
	free(s[c[3]][0]);
	if (!(s[c[3]][0] = ft_strdup(line[c[3] * 4])))
		return (1);
	while (c[3] < c[0])
	{
		c[4] = 3;
		while (c[4] >= 0)
		{
			ft_fear_fl(c, s);
			c[4]--;
		}
		c[3]++;
	}
	ft_bzero(&c[2], sizeof(int) * 7);
	return (0);
}

int			ft_conversion_fl(char **line, int *c)
{
	char	***s;
	int		**swap;

	if (c[0] == 1)
	{
		line = ft_conv_eazy_fl(line, c);
		return (ft_printmap_fl(NULL, line, c, NULL));
	}
	if (!(s = (char ***)malloc(sizeof(char **) * 40)) ||
			ft_basik_conversion_fl(line, c, s) || ft_del_stars_fl(c, s, line))
		return (ft_byby_fl(line, c, s));
	if (!(swap = (int **)malloc(sizeof(int *) * c[0])) ||
			!(ft_new_arr_fl(swap, c)))
		return (ft_byby_fl(line, c, s));
	if (!(ft_basic_calculation_fl(c, s, swap)))
		return (ft_free_swap_fl(swap, c, line, s));
	return (ft_printmap_fl(s, line, c, swap));
}
