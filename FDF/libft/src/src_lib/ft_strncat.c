/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:23:10 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:11:31 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ret;

	ret = dest;
	if (n == 0)
		return (ret);
	while (*dest)
		dest++;
	while (*src && n--)
		*(dest++) = *(src++);
	*dest = '\0';
	return (ret);
}
