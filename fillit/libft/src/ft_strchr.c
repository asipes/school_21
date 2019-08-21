/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:11:33 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 17:10:08 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char			*ret;
	unsigned char	c;

	ret = (char *)str;
	c = (unsigned char)ch;
	while (*ret)
	{
		if (*ret == c)
			return (ret);
		ret++;
	}
	if (c == 0)
		return (ret);
	return (NULL);
}
