/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:48:46 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 14:54:18 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*outa;
	unsigned char	*inar;
	unsigned char	cc;

	cc = (unsigned char)c;
	outa = (unsigned char *)s1;
	inar = (unsigned char *)s2;
	while (n)
	{
		*outa = *inar;
		outa++;
		if (*inar == cc)
			return (outa);
		inar++;
		n--;
	}
	return (NULL);
}
