/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:32:39 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 15:57:34 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*outa;

	outa = (unsigned char *)s;
	while (n)
	{
		*outa = '\0';
		outa++;
		n--;
	}
}
