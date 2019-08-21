/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:19:44 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 18:31:59 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_answer_p5(t_push *a)
{
	if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && ((a->ca + 14) < a->cb &&
		a->str[a->ca] == 'p' && a->str[a->ca + 1] == 'a' && a->str[a->ca + 3]
		== 'p' && a->str[a->ca + 4] == 'a' && a->str[a->ca + 6] == 's' &&
		a->str[a->ca + 7] == 'a' && a->str[a->ca + 9] == 'p' && a->str[a->ca +
		10] == 'b' && a->str[a->ca + 12] == 'p' && a->str[a->ca + 13] == 'b'))
	{
		a->str[a->ca] = 's';
		a->str[a->ca + 1] = 'b';
		ft_strcpy(&a->str[a->ca + 2], &a->str[a->ca + 14]);
		a->ca = 0;
		a->cb = ft_strlen(a->str);
	}
	else
		check_answer_p6(a);
}

void		check_answer_p4(t_push *a)
{
	if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && ((a->ca + 14) < a->cb &&
		a->str[a->ca] == 'p' && a->str[a->ca + 1] == 'b' && a->str[a->ca + 3]
		== 'p' && a->str[a->ca + 4] == 'b' && a->str[a->ca + 6] == 's' &&
		a->str[a->ca + 7] == 'b' && a->str[a->ca + 9] == 'p' && a->str[a->ca +
		10] == 'a' && a->str[a->ca + 12] == 'p' && a->str[a->ca + 13] == 'a'))
	{
		a->str[a->ca] = 's';
		a->str[a->ca + 1] = 'a';
		ft_strcpy(&a->str[a->ca + 2], &a->str[a->ca + 14]);
		a->ca = 0;
		a->cb = ft_strlen(a->str);
	}
	else
		check_answer_p5(a);
}

void		check_answer_p3(t_push *a)
{
	if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && (a->str[a->ca] == 'r'
		&& (a->ca + 5) < a->cb && a->str[a->ca + 3] == 'r') && ((
		a->str[a->ca + 1] == 'a' && a->str[a->ca + 4] == 'b') || (
		a->str[a->ca + 1] == 'b' && a->str[a->ca + 4] == 'a')))
	{
		a->str[a->ca + 1] = 'r';
		ft_strcpy(&a->str[a->ca + 2], &a->str[a->ca + 5]);
		a->ca = 0;
		a->cb = ft_strlen(a->str);
	}
	if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && (a->str[a->ca] == 'r'
		&& (a->ca + 5) < a->cb && a->str[a->ca + 4] == 'r') && ((
		a->str[a->ca + 2] == 'a' && a->str[a->ca + 6] == 'b') || (
		a->str[a->ca + 2] == 'b' && a->str[a->ca + 6] == 'a')))
	{
		a->str[a->ca + 2] = 'r';
		ft_strcpy(&a->str[a->ca + 3], &a->str[a->ca + 7]);
		a->ca = 0;
		a->cb = ft_strlen(a->str);
	}
	else
		check_answer_p4(a);
}

void		check_answer_p2(t_push *a)
{
	if (((a->ca == 0 || a->str[a->ca - 1] == '\n') && a->str[a->ca] == 'r' &&
		(a->ca + 6) < a->cb) && ((a->str[a->ca + 1] == 'r' &&
		a->str[a->ca + 4] == 'r' && a->str[a->ca + 2] == a->str[a->ca + 5] &&
		a->str[a->ca + 6] == '\n') || (a->str[a->ca + 3] == 'r' &&
		a->str[a->ca + 4] == 'r' && a->str[a->ca + 1] == a->str[a->ca + 5])))
	{
		ft_strcpy(&a->str[a->ca], &a->str[a->ca + 7]);
		a->ca = 0;
		a->cb = ft_strlen(a->str);
	}
	else if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && (a->str[a->ca] == 's'
		&& (a->ca + 5) < a->cb && a->str[a->ca + 3] == 's') && ((
		a->str[a->ca + 1] == 'a' && a->str[a->ca + 4] == 'b') || (
		a->str[a->ca + 1] == 'b' && a->str[a->ca + 4] == 'a')))
	{
		a->str[a->ca + 1] = 's';
		ft_strcpy(&a->str[a->ca + 2], &a->str[a->ca + 5]);
		a->ca = 0;
		a->cb = ft_strlen(a->str);
	}
	else
		check_answer_p3(a);
}

void		check_answer(t_push *a)
{
	a->ca = 0;
	a->cb = ft_strlen(a->str);
	while (a->str[a->ca])
	{
		if (a->str[a->ca] == 'p' && a->ca + 4 < a->cb && a->str[a->ca + 3] ==
		'p' && ((a->str[a->ca + 1] == 'a' && a->str[a->ca + 4] == 'b') || (
		a->str[a->ca + 1] == 'b' && a->str[a->ca + 4] == 'a')))
		{
			ft_strcpy(&a->str[a->ca], &a->str[a->ca + 6]);
			a->ca = 0;
			a->cb = ft_strlen(a->str);
		}
		else
			check_answer_p2(a);
	}
	ft_printf("%s", a->str);
}
