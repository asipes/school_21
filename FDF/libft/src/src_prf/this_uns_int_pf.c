/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_uns_int_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:12:40 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:20:00 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned long long int	this_uns_int_pf(t_tab *a, unsigned long long int i)
{
	if (a->obel_x[9] == -1)
		i = (unsigned int)i;
	if (a->obel_x[9] == 1)
		i = (unsigned long int)i;
	if (a->obel_x[9] == 2)
		i = (unsigned long long int)i;
	if (a->obel_x[9] == 3)
		i = (unsigned int)i;
	if (a->obel_x[9] == 4)
		i = (unsigned short int)i;
	if (a->obel_x[9] == 5)
		i = (unsigned char)i;
	return (i);
}
