/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:25:40 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/26 22:39:44 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh_link;

	if (!(fresh_link = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content_size + 1 <= content_size)
		return (NULL);
	if (content)
	{
		if (!(fresh_link->content = malloc(content_size + 1)))
		{
			free(fresh_link);
			return (NULL);
		}
		ft_memcpy(fresh_link->content, content, content_size);
		fresh_link->content_size = content_size;
	}
	else
	{
		fresh_link->content = NULL;
		fresh_link->content_size = 0;
	}
	fresh_link->next = NULL;
	return (fresh_link);
}
