/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:23:10 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:11:08 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(dest) + ft_strlen(src);
	if (n <= ft_strlen(dest))
		return (ft_strlen(src) + n);
	while (*dest && n--)
		dest++;
	while (*src && (n--) - 1)
		*(dest++) = *(src++);
	*dest = '\0';
	return (len);
}
