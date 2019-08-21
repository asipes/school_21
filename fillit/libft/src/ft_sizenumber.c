/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizenumber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:13:52 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 16:06:51 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_sizenumber(int n)
{
	int		i;

	i = 1;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
