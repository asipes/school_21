/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_on_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:53 by asipes            #+#    #+#             */
/*   Updated: 2019/07/21 12:14:56 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pointer_on_null(t_push *ds)
{
	ds->a_beg->next = ds->a_beg;
	ds->a_beg->prev = ds->a_beg;
	ds->temp = NULL;
	ds->run = NULL;
	ds->size_a = 0;
	ds->size_b = 0;
	ds->size_e = 0;
	ds->next = 1;
	ds->stop = 0;
	ds->i = 0;
	ds->j = 0;
	ds->fl = 1;
	ds->vis = 0;
	ds->this_swap = 0;
}
