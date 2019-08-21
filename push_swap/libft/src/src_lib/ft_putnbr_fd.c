/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:52:44 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:09:20 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		temp;
	int		i;
	int		j;
	int		k;

	if (ft_negative_l(n))
		ft_putchar_fd('-', fd);
	i = ft_sizenumber(n);
	temp = n;
	while (i--)
	{
		k = i;
		j = 1;
		while (k--)
		{
			n = n / 10;
			j = j * 10;
		}
		if (n < 0)
			n = -n;
		ft_putchar_fd(n + '0', fd);
		temp = temp % j;
		n = temp;
	}
}
