/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:56:21 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:12:18 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_bsize_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	l = 0;
	while (s[j])
	{
		if (s[j] != c && l == 0)
		{
			i++;
			l++;
		}
		if (s[j] == c)
			l = 0;
		j++;
	}
	return (i);
}

static size_t	ft_n_split(char **ret, char const *s, char c, size_t *i)
{
	while (s[i[1]])
	{
		if (s[i[1]] != c && !i[2])
		{
			i[0]++;
			i[2]++;
		}
		if (s[i[1]] != c)
			i[3]++;
		if (s[i[1]] == c)
			i[2] = 0;
		if (i[3] && !i[2])
		{
			if (!(ret[i[0] - 1] = ft_strsub(s, i[1] - i[3], i[3])))
				return (1);
			i[3] = 0;
		}
		i[1]++;
		if (i[3] && !(s[i[1]]) &&
				!(ret[i[0] - 1] = ft_strsub(s, i[1] - i[3], i[3])))
			return (1);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	size_t	*i;

	if (!(s) || !(i = (size_t *)malloc(sizeof(size_t) * 5)))
		return (NULL);
	i[4] = ft_bsize_strsplit(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * i[4] + 1)))
		return (NULL);
	ret[i[4]] = NULL;
	ft_bzero(i, sizeof(size_t) * 4);
	i[4] = ft_n_split(ret, s, c, i);
	while (i[4] && i[0] - 1)
	{
		i[0]--;
		free(ret[i[0] - 1]);
	}
	if (i[4])
	{
		free(ret);
		ret = NULL;
	}
	free(i);
	return (ret);
}
