/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 01:08:47 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:12:38 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = ft_strlen(s);
	if (i == j)
		ret = ft_strnew(0);
	else
	{
		while (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n')
			j--;
		if (!(ret = ft_strsub(s, i, j - i)))
			return (NULL);
	}
	return (ret);
}
