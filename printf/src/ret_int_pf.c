/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_int_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:26:20 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/04/29 14:04:57 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

t_tab					*ret_int_pf(t_tab *a, long long int i)
{
	if (a->obel_x[10] < 4)
	{
		i = non_uns_int_pf(a, i);
		itoa_sig_dec(a, i);
	}
	else
	{
		if (a->obel_x[10] == 5)
			a->obel_x[9] = 2;
		i = this_uns_int_pf(a, i);
		if (a->obel_x[10] == 4 || a->obel_x[10] == 5)
			itoa_oct(a, i);
		if (a->obel_x[10] == 6 || a->obel_x[10] == 23)
			itoa_uns_dec(a, i);
		if (a->obel_x[10] == 7 || a->obel_x[10] == 8)
			itoa_hex(a, i);
	}
	return (a);
}
