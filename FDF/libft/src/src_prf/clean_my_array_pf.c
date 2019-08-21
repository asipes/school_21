/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_my_array_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:03:32 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 09:03:51 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*clean_my_array_pf(t_tab *a)
{
	a->count_b = 0;
	while (a->count_b < 12)
	{
		a->obel_x[a->count_b] = -1;
		a->count_b++;
	}
	return (a);
}
