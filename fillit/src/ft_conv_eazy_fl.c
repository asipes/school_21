/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_eazy_fl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:40:21 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/01/11 03:28:38 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_conv_eazy_p3_fl(char **l, int *c)
{
	c[4] = 3;
	while (l[c[4]][0] == '\0' && c[4] > 0)
	{
		free(l[c[4]]);
		l[c[4]] = NULL;
		c[4]--;
	}
	return (l);
}

char		**ft_conv_eazy_p2_fl(char **l, int *c)
{
	c[4] = 3;
	while (c[4] >= 0)
	{
		if (!ft_isalpha(l[0][c[4]]) && !ft_isalpha(l[1][c[4]]) &&
				!ft_isalpha(l[2][c[4]]) && !ft_isalpha(l[3][c[4]]) &&
				!ft_isalpha(l[c[4]][0]) && !ft_isalpha(l[c[4]][1]) &&
				!ft_isalpha(l[c[4]][2]) && !ft_isalpha(l[c[4]][3]))
		{
			ft_strcpy(&l[0][c[4]], &l[0][c[4] + 1]);
			ft_strcpy(&l[1][c[4]], &l[1][c[4] + 1]);
			ft_strcpy(&l[2][c[4]], &l[2][c[4] + 1]);
			ft_strcpy(&l[3][c[4]], &l[3][c[4] + 1]);
			c[5] = c[4];
			while (c[5] < 4)
			{
				if (l[c[5] + 1])
					ft_memcpy(l[c[5]], l[c[5] + 1], 4);
				else
					ft_bzero(l[c[5]], sizeof(char) * 4);
				c[5]++;
			}
		}
		c[4]--;
	}
	return (ft_conv_eazy_p3_fl(l, c));
}

char		**ft_conv_eazy_p1_fl(char **l, int *c)
{
	char	q;

	c[4] = 1;
	while (c[4] < 4)
	{
		if (ft_isalpha(l[0][c[4]]) || ft_isalpha(l[1][c[4]]) ||
				ft_isalpha(l[2][c[4]]) || ft_isalpha(l[3][c[4]]))
			while (c[4] > 0 && l[0][c[4] - 1] == '.' && l[1][c[4] - 1] == '.'
					&& l[2][c[4] - 1] == '.' && l[3][c[4] - 1] == '.')
			{
				c[6] = 0;
				while (c[6] < 4)
				{
					q = l[c[6]][c[4]];
					l[c[6]][c[4]] = l[c[6]][c[4] - 1];
					l[c[6]][c[4] - 1] = q;
					c[6]++;
				}
				c[4]--;
			}
		c[4]++;
	}
	return (ft_conv_eazy_p2_fl(l, c));
}

char		**ft_conv_eazy_fl(char **l, int *c)
{
	char	*swap;

	c[4] = 1;
	while (c[4] < 4)
	{
		if (l[c[4]] && (ft_isalpha(l[c[4]][0]) || ft_isalpha(l[c[4]][1]) ||
				ft_isalpha(l[c[4]][2]) || ft_isalpha(l[c[4]][3])))
			while (c[4] > 0 && l[c[4] - 1][0] == '.' && l[c[4] - 1][1] == '.'
					&& l[c[4] - 1][2] == '.' && l[c[4] - 1][3] == '.')
			{
				swap = l[c[4]];
				l[c[4]] = l[c[4] - 1];
				l[c[4] - 1] = swap;
				c[4]--;
			}
		c[4]++;
	}
	return (ft_conv_eazy_p1_fl(l, c));
}
