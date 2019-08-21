/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:18:24 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/11 15:49:06 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *st_in, const char *st_fi, size_t n)
{
	size_t	i;
	size_t	j;
	char	*ans;

	i = 0;
	j = 0;
	while (st_in[i] && st_fi[j] && i < n)
	{
		if (st_in[i] == st_fi[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	if (j < ft_strlen(st_fi))
		return (NULL);
	ans = (char *)st_in + i - j;
	return (ans);
}
