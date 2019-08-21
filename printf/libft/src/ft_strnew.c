/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:59:14 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/25 16:08:01 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	if (size + 1 <= size)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
