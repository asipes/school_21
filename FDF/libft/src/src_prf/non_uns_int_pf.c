/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_uns_int_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:11:49 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:21:43 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long long int			non_uns_int_pf(t_tab *a, long long int i)
{
	if (a->obel_x[10] == 2)
		return (i);
	if (a->obel_x[9] == -1)
		i = (int)i;
	if (a->obel_x[9] == 1)
		i = (long int)i;
	if (a->obel_x[9] == 3)
		i = (int)i;
	if (a->obel_x[9] == 4)
		i = (short int)i;
	if (a->obel_x[9] == 5)
		i = (char)i;
	if (a->obel_x[9] == 7)
		i = (size_t)i;
	return (i);
}
