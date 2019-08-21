/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_al_var_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:56:56 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:21:53 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	left_al_var_pf(t_tab *a)
{
	a->zero = a->obel_x[8] - a->len_num;
	if (a->zero < 0)
		a->zero = 0;
	a->space = a->obel_x[6] - (a->len_num + a->zero + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->zero + a->len_num + a->space;
}
