/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emergency_exit_fl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 20:40:30 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/01/20 15:36:46 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_read_fll(char *line, int *count)
{
	count[7] = 0;
	count[8] = 0;
	count[1]++;
	count[0] = count[0] + count[1] / 4;
	count[2] = 0;
	while (line[count[7]])
	{
		if (line[count[7]] == '.' || line[count[7]] == '#')
		{
			if (line[count[7]] == '#' && count[1] != 4)
				line[count[7]] = line[count[7]] - '#' + 'A' + count[0];
			if (line[count[7]] == '#' && count[1] == 4)
				line[count[7]] = line[count[7]] - '#' + 'A' + count[0] - 1;
			count[8]++;
		}
		count[7]++;
	}
	if (count[7] == 4 && count[8] == 4)
		return (0);
	return (1);
}

int			ft_read_fl(int fd, char **line, int *coun)
{
	while ((coun[5] = get_next_line(fd, &line[coun[6]])) > 0)
	{
		if (*line[coun[6]])
			coun[7] = ft_read_fll(line[coun[6]], coun);
		else
		{
			coun[2]++;
			if (coun[1] % 4)
				return (1);
			coun[1] = 0;
			free(line[coun[6]]);
			coun[6]--;
		}
		if (coun[0] > 26 || coun[1] > 4 || coun[2] > 1 || coun[7] == 1)
			return (1);
		coun[6]++;
	}
	if (coun[5] < 0 || coun[6] == 0 || coun[6] % 4)
		return (1);
	if (coun[0] < 1 || coun[2] > 0)
		return (1);
	line[coun[6]] = NULL;
	return (0);
}

void		ft_compliance_fll(char **l, int *c)
{
	while (c[4] < 4)
	{
		if (l[c[2]][c[4]] != '.' && l[c[2]][c[4]])
		{
			c[5]++;
			c[7]++;
			if (l[c[2]][c[4]] == l[c[2]][c[4] + 1])
				c[6]++;
			if (c[2] < c[1] - 1 && l[c[2]][c[4]] == l[c[2] + 1][c[4]])
				c[6]++;
		}
		c[4]++;
	}
	c[2]++;
	c[3]++;
	c[4] = 0;
}

int			ft_compliance_fl(char **line, int *count)
{
	count[1] = count[6];
	ft_bzero(&count[2], sizeof(int) * 8);
	while (count[2] < count[1])
	{
		while (count[3] < 4)
			ft_compliance_fll(line, count);
		if (count[5] != 4 || count[6] < 3)
		{
			count[6] = count[1];
			return (1);
		}
		ft_bzero(&count[3], sizeof(int) * 4);
	}
	count[2] = 0;
	while (count[2] * count[2] < count[7])
		count[2]++;
	count[7] = 0;
	return (0);
}

int			ft_emergency_exit_fl(int fd, char **line, int *counter)
{
	if (line && (ft_read_fl(fd, line, counter)
				|| ft_compliance_fl(line, counter)))
	{
		counter[6]--;
		while (counter[6] >= 0 && (counter[1] || counter[2]))
		{
			free(line[counter[6]]);
			counter[6]--;
		}
		free(line);
		free(counter);
		close(fd);
		return (1);
	}
	close(fd);
	if (!line)
	{
		free(counter);
		return (1);
	}
	return (0);
}
