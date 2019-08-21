/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:01 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/04/29 13:55:56 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab		*no_valid_pf(t_tab *a)
{
	a->p_char = a->temp[0];
	ft_strcpy(a->temp, &(a->temp[1]));
	a = ret_char_pf(a, a->p_char);
	a->abs_len += ft_strlen(a->temp);
	write(1, a->temp, ft_strlen(a->temp));
	free(a->temp);
	return (a);
}

t_tab		*array_of_param_pf(t_tab *a)
{
	if (!(a->ty = ft_strdup("dDioOuxXfFeEgGaAcCsSpnU")) ||
			!(a->fl = ft_strdup(" +-#0lhjztL123456789.*")) ||
			!(a->tf = ft_strjoin(a->fl, a->ty)))
		return (memory_error_pf(a));
	return (a);
}

t_tab		*check_valid_pf(t_tab *a)
{
	if (!(a->temp[0]))
	{
		a->abs_len++;
		free(a->temp);
		ft_putchar('%');
		return (a);
	}
	while (a->temp)
	{
		a->count_a = 0;
		while (a->temp[0] != a->tf[a->count_a] && a->tf[a->count_a]
				&& a->temp[0])
			a->count_a++;
		if (a->tf[a->count_a])
			a = hard_check_pf(a);
		else
			return (no_valid_pf(a));
		if (a->obel_x[2] == 7)
			return (a);
	}
	return (a);
}
