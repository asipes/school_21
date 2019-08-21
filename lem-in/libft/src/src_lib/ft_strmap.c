/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:58:33 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:11:19 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*new;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (sizeof(char) * len + 1 <= sizeof(char) * len)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	new[len] = '\0';
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
