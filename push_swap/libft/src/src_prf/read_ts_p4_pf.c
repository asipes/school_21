/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ts_p4_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:07:12 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:20:14 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*read_ts_p4_pf(t_tab *a)
{
	a->count_b = 0;
	while (a->ty[a->count_b] != a->temp[0])
		a->count_b++;
	a->obel_x[10] = a->count_b + 1;
	ft_strcpy(a->temp, &(a->temp[1]));
	a = give_me_param_pf(a);
	a->abs_len += ft_strlen(a->temp);
	write(1, a->temp, ft_strlen(a->temp));
	if (a->temp)
	{
		free(a->temp);
		a->temp = NULL;
	}
	a->obel_x[2] = 7;
	return (a);
}
