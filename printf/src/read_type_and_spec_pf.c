/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_type_and_spec_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:47:51 by asipes            #+#    #+#             */
/*   Updated: 2019/04/29 21:39:10 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

t_tab		*read_ts_p3_pf(t_tab *a)
{
	while (a->temp[0] == 'z')
	{
		a->obel_x[9] = 7;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	while (a->temp[0] == 't')
	{
		a->obel_x[9] = 8;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_ts_p4_pf(a));
	return (a);
}

t_tab		*read_ts_p2_pf(t_tab *a)
{
	while (a->temp[0] == 'h')
	{
		if (a->temp[1] == 'h')
		{
			if (a->obel_x[9] < 1 || a->obel_x[9] == 3)
				a->obel_x[9] = 5;
			ft_strcpy(a->temp, &(a->temp[1]));
		}
		else if (a->obel_x[9] < 1 || a->obel_x[9] == 3 || a->obel_x[9] == 5)
			a->obel_x[9] = 4;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	while (a->temp[0] == 'j')
	{
		a->obel_x[9] = 6;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_ts_p3_pf(a));
	return (a);
}

t_tab		*read_type_and_spec_pf(t_tab *a)
{
	while (a->temp[0] == 'l')
	{
		if (a->temp[1] == 'l')
		{
			a->obel_x[9] = 2;
			ft_strcpy(a->temp, &(a->temp[2]));
		}
		else
		{
			if (a->obel_x[9] != 2)
				a->obel_x[9] = 1;
			ft_strcpy(a->temp, &(a->temp[1]));
		}
	}
	while (a->temp[0] == 'L')
	{
		if (a->obel_x[9] < 1)
			a->obel_x[9] = 3;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_ts_p2_pf(a));
	return (a);
}
