/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_put_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:22:44 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:20:59 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	other_put_pf(t_tab *a, unsigned long long int num)
{
	a->len_num = numlen_sig_pf(num, 10);
	left_al_var_pf(a);
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	a->stop = a->space;
	put_space_pf(a);
	if (a->sym == '-' || a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop += (a->sig + a->zero);
	put_zero_pf(a);
	a->stop += (a->len_num - 1);
	put_num_pf(a, num);
	write(1, a->mass, a->len);
	free(a->mass);
}
