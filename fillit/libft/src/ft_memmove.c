/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:28:53 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/03 20:07:56 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*des;
	unsigned char	*sr;

	sr = (unsigned char *)src;
	des = (unsigned char *)dest;
	while (n)
	{
		if (sr < des)
			des[n - 1] = sr[n - 1];
		else
		{
			*des = *sr;
			des++;
			sr++;
		}
		n--;
	}
	return (dest);
}
