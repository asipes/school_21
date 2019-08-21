/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_answer_p6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:20:02 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:20:02 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		hard_check5(t_push *a, int i)
{
	while (i < a->cb)
	{
		if (a->str[i] == 'p' || (a->str[i] == 'r' && i + 2 < a->cb && ((
			a->str[i + 1] == 'b' || (a->str[i + 1] == 'r' && a->str[i + 2] ==
			'\n')) || (a->str[i + 1] == 'r' && (a->str[i + 2] == 'r' ||
			a->str[i + 2] == 'b')))))
			i = a->cb;
		else if (a->str[i - 1] == '\n' && a->str[i] == 's' && a->str[i + 1] ==
			'b')
		{
			a->str[a->ca + 1] = 's';
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

void		hard_check6(t_push *a, int i)
{
	while (i < a->cb)
	{
		if (a->str[i] == 'p' || (a->str[i] == 'r' && i + 2 < a->cb && ((
			a->str[i + 1] == 'a' || (a->str[i + 1] == 'r' && a->str[i + 2] ==
			'\n')) || (a->str[i + 1] == 'r' && (a->str[i + 2] == 'r' ||
			a->str[i + 2] == 'a')))))
			i = a->cb;
		else if (a->str[i - 1] == '\n' && a->str[i] == 's' && a->str[i + 1] ==
			'a')
		{
			a->str[a->ca + 1] = 's';
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

void		hard_check_answer(t_push *a)
{
	if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && (a->ca + 4) < a->cb &&
		a->str[a->ca] == 'r' && a->str[a->ca + 1] == 'a')
		hard_check1(a, a->ca + 3);
	else if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && (a->ca + 4) < a->cb &&
		a->str[a->ca] == 'r' && a->str[a->ca + 1] == 'b')
		hard_check2(a, a->ca + 3);
	else if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && (a->ca + 5) < a->cb &&
		a->str[a->ca] == 'r' && a->str[a->ca + 1] == 'r' &&
		a->str[a->ca + 2] == 'a')
		hard_check3(a, a->ca + 4);
	else if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && (a->ca + 5) < a->cb &&
		a->str[a->ca] == 'r' && a->str[a->ca + 1] == 'r' &&
		a->str[a->ca + 2] == 'b')
		hard_check4(a, a->ca + 4);
	else if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && (a->ca + 4) < a->cb &&
		a->str[a->ca] == 's' && a->str[a->ca + 1] == 'a')
		hard_check5(a, a->ca + 3);
	else if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && (a->ca + 4) < a->cb &&
		a->str[a->ca] == 's' && a->str[a->ca + 1] == 'b')
		hard_check6(a, a->ca + 3);
	else
		a->ca++;
}

void		check_answer_p6(t_push *a)
{
	if ((a->ca == 0 || a->str[a->ca - 1] == '\n') && ((a->ca + 5) < a->cb &&
		a->str[a->ca] == 's' && a->str[a->ca + 3] == 's' && a->str[a->ca + 1]
		== a->str[a->ca + 4]))
	{
		ft_strcpy(&a->str[a->ca], &a->str[a->ca + 6]);
		a->ca = 0;
		a->cb = ft_strlen(a->str);
	}
	else
		hard_check_answer(a);
}
