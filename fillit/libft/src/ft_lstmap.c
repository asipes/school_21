/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:41:10 by ldonnor-          #+#    #+#             */
/*   Updated: 2018/12/26 22:24:08 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_lmn(t_list *lst, t_list *(*f)(t_list *elem), t_list *alfa)
{
	t_list	*prew;

	if (lst && f)
	{
		ft_lmn(lst->next, f, alfa);
		if (!(prew = ft_lstnew(lst->content, lst->content_size)))
			ft_lstdeldel(alfa->next);
		else
		{
			prew = f(prew);
			prew->next = alfa->next;
			alfa->next = prew;
		}
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alfa;
	t_list	*prew;

	if (!f || !lst || !(alfa = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	ft_lmn(lst, f, alfa);
	prew = alfa->next;
	free(alfa);
	return (prew);
}
