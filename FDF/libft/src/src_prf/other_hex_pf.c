/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_hex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:12:38 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:21:07 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	other_hex_pf(t_tab *a, unsigned long long int num)
{
	hex_chec_len_pf(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->space;
	put_space_pf(a);
	if (a->sig == 2)
	{
		a->mass[a->count_m] = '0';
		a->mass[a->count_m + 1] = a->sym;
		a->count_m += 2;
	}
	a->stop += a->sig + a->zero;
	put_zero_pf(a);
	a->stop += (a->len_num - 1);
	hex_put_num_pf(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}
