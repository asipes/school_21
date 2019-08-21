/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:41 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 17:17:42 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push *ds)
{
	int temp_val;

	if (ds->size_a > 1)
	{
		temp_val = ds->a_beg->val;
		ds->a_beg->val = ds->a_beg->next->val;
		ds->a_beg->next->val = temp_val;
		temp_val = ds->a_beg->ord;
		ds->a_beg->ord = ds->a_beg->next->ord;
		ds->a_beg->next->ord = temp_val;
		temp_val = ds->a_beg->flag;
		ds->a_beg->flag = ds->a_beg->next->flag;
		ds->a_beg->next->flag = temp_val;
	}
}

void	sb(t_push *ds)
{
	int temp_val;

	if (ds->size_b > 1)
	{
		temp_val = ds->b_beg->val;
		ds->b_beg->val = ds->b_beg->next->val;
		ds->b_beg->next->val = temp_val;
		temp_val = ds->b_beg->ord;
		ds->b_beg->ord = ds->b_beg->next->ord;
		ds->b_beg->next->ord = temp_val;
		temp_val = ds->b_beg->flag;
		ds->b_beg->flag = ds->b_beg->next->flag;
		ds->b_beg->next->flag = temp_val;
	}
}

void	ss(t_push *ds)
{
	sa(ds);
	sb(ds);
}
