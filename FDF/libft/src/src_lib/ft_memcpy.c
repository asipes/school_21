/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:49:23 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:08:26 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *outarr, const void *inarr, size_t n)
{
	size_t			i;
	unsigned char	*outa;
	unsigned char	*inar;

	outa = (unsigned char *)outarr;
	inar = (unsigned char *)inarr;
	i = 0;
	if (outa == NULL && inar == NULL && (n <= 0))
		outa[i] = inar[i];
	while (i < n)
	{
		outa[i] = inar[i];
		i++;
	}
	return (outarr);
}
