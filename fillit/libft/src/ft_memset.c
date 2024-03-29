/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:17:09 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/03 19:09:15 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*outa;

	outa = (unsigned char *)memptr;
	while (num)
	{
		*outa = val;
		outa++;
		num--;
	}
	return (memptr);
}
