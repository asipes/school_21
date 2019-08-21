/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:11:14 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:11:23 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*new;

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
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
