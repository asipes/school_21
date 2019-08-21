/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_check_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:48:18 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/04/09 17:54:39 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab		*hard_check_p2_pf(t_tab *a)
{
	while (a->temp[0] == ' ' || a->temp[0] == '+' || a->temp[0] == '-' ||
			a->temp[0] == '#')
	{
		if (a->temp[0] == '#')
			a->obel_x[3] = 1;
		if (a->temp[0] == ' ' && a->obel_x[4] < 1)
			a->obel_x[4] = 1;
		if (a->temp[0] == '+')
			a->obel_x[4] = 2;
		if (a->temp[0] == '-')
			a->obel_x[5] = 1;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_type_and_spec_pf(a));
	return (a);
}

t_tab		*hard_check_p1_pf(t_tab *a)
{
	if (ft_isdigit(a->temp[0]))
	{
		a->int_temp = ft_atoi(a->temp);
		while (ft_isdigit(a->temp[0]))
			ft_strcpy(a->temp, &(a->temp[1]));
		if (a->temp[0] == '$')
		{
			a->parametr = a->int_temp;
			ft_strcpy(a->temp, &(a->temp[1]));
		}
		else
			a->obel_x[6] = a->int_temp;
	}
	while (a->temp[0] == '*')
	{
		a = duck_star_pf(a);
		a->obel_x[6] = a->int_temp;
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (hard_check_p2_pf(a));
	return (a);
}

t_tab		*read_star_pf(t_tab *a)
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

t_tab		*duck_star_pf(t_tab *a)
{
	a->int_temp = -1;
	ft_strcpy(a->temp, &(a->temp[1]));
	if (ft_isdigit(a->temp[0]))
	{
		a->count_b = 0;
		while (ft_isdigit(a->temp[a->count_b]))
			a->count_b++;
		if (a->temp[a->count_b] == '$')
		{
			a->int_temp = ft_atoi(a->temp);
			while (ft_isdigit(a->temp[0]))
				ft_strcpy(a->temp, &(a->temp[1]));
			ft_strcpy(a->temp, &(a->temp[1]));
			if (a->int_temp == 0)
				return (a);
			a->obel_x[1] = a->int_temp;
			a = read_star_pf(a);
			return (a);
		}
	}
	a->obel_x[1] = a->parametr;
	a = read_star_pf(a);
	a->parametr++;
	return (a);
}

t_tab		*hard_check_pf(t_tab *a)
{
	while (a->temp[0] == '.')
	{
		ft_strcpy(a->temp, &(a->temp[1]));
		a->int_temp = 0;
		if (ft_isdigit(a->temp[0]))
		{
			a->int_temp = ft_atoi(&(a->temp[0]));
			while (ft_isdigit(a->temp[0]))
				ft_strcpy(a->temp, &(a->temp[1]));
		}
		else if (a->temp[0] == '*')
			a = duck_star_pf(a);
		a->obel_x[8] = a->int_temp;
	}
	while (a->temp[0] == '0')
	{
		if (a->obel_x[5] < 0)
			a->obel_x[5] = 0;
		ft_strcpy(a->temp, &(a->temp[1]));
		if (a->temp[0] == '$')
			return (no_valid_pf(a));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (hard_check_p1_pf(a));
	return (a);
}
