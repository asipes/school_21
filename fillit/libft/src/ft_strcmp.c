/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:48:17 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/15 16:52:44 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int				i;
	unsigned char	*str3;
	unsigned char	*str4;

	str3 = (unsigned char *)str1;
	str4 = (unsigned char *)str2;
	i = 0;
	while (str3[i] == str4[i] && str3[i])
		i++;
	return (str3[i] - str4[i]);
}
