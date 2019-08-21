/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:07:26 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 14:52:05 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*str3;
	unsigned char	*str4;

	str3 = (unsigned char *)str1;
	str4 = (unsigned char *)str2;
	i = 0;
	if (n < 1)
		return (0);
	while (str3[i] == str4[i] && str3[i] && i < n - 1)
		i++;
	return (str3[i] - str4[i]);
}
