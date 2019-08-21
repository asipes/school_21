/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_left_al_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:13:29 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:22:28 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	hex_left_al_pf(t_tab *a, unsigned long long int num)
{
	hex_chec_len_pf(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->sig == 2)
	{
		a->mass[a->count_m] = '0';
		a->mass[a->count_m + 1] = a->sym;
		a->count_m += 2;
	}
	a->stop = a->sig + a->zero;
	put_zero_pf(a);
	a->stop += a->len_num - 1;
	hex_put_num_pf(a, num);
	a->stop = a->count_m + a->space;
	put_space_pf(a);
	write(1, a->mass, a->len);
	free(a->mass);
}
