/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:54:47 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:09:25 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr(int n)
{
	int		temp;
	int		i;
	int		j;
	int		k;

	if (ft_negative_l(n))
		ft_putchar('-');
	i = ft_sizenumber(n);
	temp = n;
	while (i--)
	{
		k = i;
		j = 1;
		while (k--)
		{
			j = j * 10;
			n = n / 10;
		}
		if (n < 0)
			n = -n;
		ft_putchar(n + '0');
		temp = temp % j;
		n = temp;
	}
}
