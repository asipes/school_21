/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:14:28 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/05 15:40:26 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	gnl_end(const int fd, int j, char *bufer, char **temp)
{
	char	*mem_temp;
	int		size_read;

	size_read = 0;
	if (temp[fd][j] == '\0')
	{
		size_read = read(fd, bufer, BUFF_SIZE);
		mem_temp = temp[fd];
		temp[fd] = ft_strjoin(temp[fd], bufer);
		if (ft_strlen(mem_temp) && ft_strequ(mem_temp, temp[fd]))
		{
			free(mem_temp);
			free(bufer);
			return (2);
		}
		free(mem_temp);
		ft_bzero(bufer, BUFF_SIZE);
	}
	if (size_read < BUFF_SIZE && temp[fd][0] == '\0')
	{
		free(bufer);
		return (0);
	}
	return (1);
}

static int	gnl_line(char **line, char *temp, int j, int i)
{
	*line = ft_strsub(temp, 0, j);
	if (i == 2)
	{
		ft_bzero(temp, j);
		i = 0;
	}
	if (!(*line))
		return (3);
	return (i);
}

static int	gnl_ret(char **line, char *temp, char *bufer, int j)
{
	if (temp[j] == '\n')
	{
		if (gnl_line(line, temp, j, 0))
			return (3);
		ft_strcpy(temp, &temp[j + 1]);
		free(bufer);
		return (0);
	}
	return (1);
}

static int	gnl_aut(const int fd, char **line, char **bufer, char **temp)
{
	*bufer = NULL;
	if (BUFF_SIZE < 1 || fd < 0 || line == NULL ||
			!(*bufer = ft_strnew(BUFF_SIZE)) || read(fd, *bufer, 0) < 0 ||
			(temp[fd] == NULL && !(temp[fd] = ft_strnew(1))))
	{
		if (*bufer)
		{
			free(*bufer);
		}
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		*bufer;
	int			j;
	int			i;
	static char	*temp[255];

	if (gnl_aut(fd, line, &bufer, temp))
		return (-1);
	j = 0;
	i = 0;
	while (1)
	{
		if (i == 3)
			return (-1);
		if (i != 3 && !(i = gnl_end(fd, j, bufer, temp)))
			return (0);
		if (i == 2 && !(i = gnl_line(line, temp[fd], j, i)))
			return (1);
		while (i != 3 && temp[fd][j] != '\n' && temp[fd][j] != '\0')
			j++;
		if (i != 3 && !(i = gnl_ret(line, temp[fd], bufer, j)))
			return (1);
	}
}
