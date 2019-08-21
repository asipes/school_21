/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:49:23 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 16:14:37 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *outarr, const void *inarr, size_t n)
{
	size_t			i;
	unsigned char	*outa;
	unsigned char	*inar;

	outa = (unsigned char *)outarr;
	inar = (unsigned char *)inarr;
	i = 0;
	while (i < n)
	{
		outa[i] = inar[i];
		i++;
	}
	return (outarr);
}
