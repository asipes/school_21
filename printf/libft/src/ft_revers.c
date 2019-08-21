/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:41:13 by asipes            #+#    #+#             */
/*   Updated: 2019/03/17 12:24:30 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_revers(char *src)
{
	char	*tmp;
	char	a;
	char	b;
	int		len;
	int		i;

	i = 0;
	tmp = src;
	len = ft_strlen(tmp);
	while (i < len--)
	{
		a = tmp[i];
		b = tmp[len];
		tmp[i] = b;
		tmp[len] = a;
		i++;
	}
}
