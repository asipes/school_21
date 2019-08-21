/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_x_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:02:37 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 09:03:10 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*feed_x_pf(t_tab *a)
{
	if (a->obel_x[0] == 1 &&
			!(a->temp = ft_strsub(a->form, 1, a->count_a - 1)))
		return (memory_error_pf(a));
	if (a->obel_x[0] < 1)
	{
		if (a->obel_x[0] &&
				!(a->temp = ft_strsub(a->form, 1, a->count_a - 1)))
			return (memory_error_pf(a));
		if (!(a->obel_x[0]) && !(a->temp = ft_strsub(a->form, 0, a->count_a)))
			return (memory_error_pf(a));
		write(1, a->temp, ft_strlen(a->temp));
		a->abs_len += ft_strlen(a->temp);
		free(a->temp);
	}
	a->form = ft_strcpy(a->form, &(a->form[a->count_a]));
	if (a->obel_x[0] == 1)
		a = check_valid_pf(a);
	a->count_a = 0;
	return (a);
}
