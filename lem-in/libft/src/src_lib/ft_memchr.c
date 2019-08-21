/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:37:19 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:08:11 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
