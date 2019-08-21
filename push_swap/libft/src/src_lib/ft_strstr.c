/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:37:49 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:12:28 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *st_in, const char *st_fi)
{
	size_t	i;
	size_t	j;
	char	*ans;

	i = 0;
	j = 0;
	while (st_in[i] && st_fi[j])
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
