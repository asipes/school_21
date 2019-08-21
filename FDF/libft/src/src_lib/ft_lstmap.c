/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:29:12 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:07:47 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*current;
	t_list	*prev;

	if (!lst)
		return (NULL);
	current = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	list = current;
	prev = current;
	lst = lst->next;
	while (lst)
	{
		current = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		prev->next = current;
		prev = prev->next;
		lst = lst->next;
	}
	return (list);
}
