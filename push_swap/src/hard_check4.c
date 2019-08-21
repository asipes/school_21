/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_check4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:03 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:17:05 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		hard_check1(t_push *a, int i)
{
	while (i < a->cb)
	{
		if (a->str[i] == 'p' || ((i + 1 < a->cb) && a->str[i] == 's' &&
			(a->str[i + 1] == 's' || a->str[i + 1] == 'b')) || ((i + 2 < a->cb)
			&& a->str[i] == 'r' && a->str[i + 1] == 'r' && (a->str[i + 2] == 'r'
			|| a->str[i + 2] == 'b')))
			i = a->cb;
		else if (a->str[i - 1] == '\n' && a->str[i] == 'r' && a->str[i + 1] ==
			'b')
		{
			a->str[a->ca + 1] = 'r';
			ft_strcpy(&a->str[i - 1], &a->str[i + 2]);
			a->ca = -1;
			a->cb = ft_strlen(a->str);
			i = a->cb;
		}
		else
			i++;
	}
	a->ca++;
}

void		hard_check2(t_push *a, int i)
{
	while (i < a->cb)
	{
		if (a->str[i] == 'p' || ((i + 1 < a->cb) && a->str[i] == 's' &&
			(a->str[i + 1] == 's' || a->str[i + 1] == 'a')) || ((i + 2 < a->cb)
			&& a->str[i] == 'r' && a->str[i + 1] == 'r' && (a->str[i + 2] == 'r'
			|| a->str[i + 2] == 'a')))
			i = a->cb;
		else if (a->str[i - 1] == '\n' && a->str[i] == 'r' && a->str[i + 1] ==
			'a')
		{
			a->str[a->ca + 1] = 'r';
			ft_strcpy(&a->str[i - 1], &a->str[i + 2]);
			a->ca = -1;
			a->cb = ft_strlen(a->str);
			i = a->cb;
		}
		else
			i++;
	}
	a->ca++;
}

void		hard_check3(t_push *a, int i)
{
	while (i < a->cb)
	{
		if (a->str[i] == 'p' || ((i + 1 < a->cb) && a->str[i] == 's' &&
			(a->str[i + 1] == 's' || a->str[i + 1] == 'b')) || ((i + 2 < a->cb)
			&& a->str[i] == 'r' && (a->str[i + 1] == 'r' || a->str[i + 1] ==
			'b') && a->str[i + 2] == '\n'))
			i = a->cb;
		else if (a->str[i - 1] == '\n' && a->str[i] == 'r' && a->str[i + 1] ==
			'r' && a->str[i + 2] == 'b')
		{
			a->str[a->ca + 2] = 'r';
			ft_strcpy(&a->str[i - 1], &a->str[i + 3]);
			a->ca = -1;
			a->cb = ft_strlen(a->str);
			i = a->cb;
		}
		else
			i++;
	}
	a->ca++;
}

void		hard_check4(t_push *a, int i)
{
	while (i < a->cb)
	{
		if (a->str[i] == 'p' || ((i + 1 < a->cb) && a->str[i] == 's' &&
			(a->str[i + 1] == 's' || a->str[i + 1] == 'a')) || ((i + 2 < a->cb)
			&& a->str[i] == 'r' && (a->str[i + 1] == 'r' || a->str[i + 1] ==
			'a') && a->str[i + 2] == '\n'))
			i = a->cb;
		else if (a->str[i - 1] == '\n' && a->str[i] == 'r' && a->str[i + 1] ==
			'r' && a->str[i + 2] == 'a')
		{
			a->str[a->ca + 2] = 'r';
			ft_strcpy(&a->str[i - 1], &a->str[i + 3]);
			a->ca = -1;
			a->cb = ft_strlen(a->str);
			i = a->cb;
		}
		else
			i++;
	}
	a->ca++;
}
