/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_space_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:23:24 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:20:42 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	put_space_pf(t_tab *a)
{
	while (a->count_m < a->stop)
	{
		a->mass[a->count_m] = ' ';
		a->count_m++;
	}
}