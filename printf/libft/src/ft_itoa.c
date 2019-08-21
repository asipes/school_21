/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:54:26 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 15:58:16 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	*str;

	sign = ft_negative_l(n);
	i = ft_sizenumber(n);
	if (!(str = ft_strnew(i + sign)))
		return (NULL);
	while (i)
	{
		i--;
		if (sign)
			str[i + sign] = n % 10 * -1 + '0';
		if (!sign)
			str[i + sign] = n % 10 + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
