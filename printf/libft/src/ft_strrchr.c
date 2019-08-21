/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:47:00 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 17:12:19 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char			*ret;
	unsigned char	c;

	ret = (char *)str;
	c = (unsigned char)ch;
	while (*ret)
		ret++;
	while (ret >= str)
	{
		if (*ret == c)
			return (ret);
		ret--;
	}
	return (NULL);
}
