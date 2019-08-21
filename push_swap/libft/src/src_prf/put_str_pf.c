/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:13:19 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:20:39 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		put_str_pf(t_tab *a, char *string)
{
	if (a->obel_x[5] == 0 || a->obel_x[5] == -1)
	{
		write(1, a->mass, a->count_m);
		write(1, string == NULL ? "(null)" : string, a->len_num);
	}
	else if (a->obel_x[5] != 1)
		write(1, string == NULL ? "(null)" : string, a->len_num);
	else
	{
		write(1, string == NULL ? "(null)" : string, a->len_num);
		write(1, a->mass, a->count_m);
	}
}
