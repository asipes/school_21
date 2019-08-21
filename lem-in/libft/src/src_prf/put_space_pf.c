/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_space_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:23:24 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:38:21 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_space_pf(t_tab *a)
{
	while (a->count_m < a->stop)
	{
		a->mass[a->count_m] = ' ';
		a->count_m++;
	}
}

void	put_str_pf(t_tab *a, char *string)
{
	if (a->obel_x[5] == 0 || a->obel_x[5] == -1)
	{
		write(1, a->mass, a->count_m);
		write(1, string == NULL ? "(null)" : string, a->len_num);
	}
	else if (a->obel_x[5] != 1)
		write(1, string == NULL ? "(null)" : string, a->len_num);
	else
	{
		write(1, string == NULL ? "(null)" : string, a->len_num);
		write(1, a->mass, a->count_m);
	}
}

void	put_zero_pf(t_tab *a)
{
	while (a->count_m < a->stop)
	{
		a->mass[a->count_m] = '0';
		a->count_m++;
	}
}

t_tab	*read_star_pf(t_tab *a)
{
	va_list	cap;

	va_copy(cap, a->ap);
	a->count_b = 0;
	while (a->count_b < a->obel_x[1])
	{
		a->int_temp = va_arg(cap, int);
		a->count_b++;
	}
	va_end(cap);
	a->obel_x[1] = -1;
	a->count_b = 0;
	return (a);
}

t_tab	*read_ts_p2_pf(t_tab *a)
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
