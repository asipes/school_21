/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:37:19 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 15:00:21 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*arra;
	unsigned char	cc;

	cc = (unsigned char)c;
	arra = (unsigned char *)arr;
	while (n)
	{
		if (*arra == cc)
			return (arra);
		arra++;
		n--;
	}
	return (NULL);
}
