/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:35:43 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 15:56:37 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	long long unsigned int	ret;
	int						sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (*str == '+' && sign == 1)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*(str++) - '0');
		if (sign == 1 && ret > 9223372036854775806)
			return (-1);
		if (sign == -1 && ret > 9223372036854775807)
			return (0);
	}
	return (ret * sign);
}
