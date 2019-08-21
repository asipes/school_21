/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_param_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:20:06 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:39:30 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*array_of_param_pf(t_tab *a)
{
	if (!(a->ty = ft_strdup("dDioOuxXfFeEgGaAcCsSpnU")) ||
			!(a->fl = ft_strdup(" +-#0lhjztL123456789.*")) ||
			!(a->tf = ft_strjoin(a->fl, a->ty)))
		return (memory_error_pf(a));
	return (a);
}

void	char_left_al_pf(t_tab *a, char c)
{
	a->space = a->obel_x[6];
	a->mass = ft_strnew(a->space);
	a->abs_len += a->space;
	a->mass[a->count_m] = c;
	a->count_m++;
	a->stop = a->space;
	put_space_pf(a);
	write(1, a->mass, a->space);
	free(a->mass);
}

void	check_inf_pf(t_tab *a, double num)
{
	if (num > 0)
	{
		if (a->obel_x[4] == 1)
		{
			if (a->obel_x[7])
				ret_string_pf(a, " inf");
			else
				ret_string_pf(a, " INF");
		}
		else if (a->obel_x[4] == 2)
		{
			if (a->obel_x[7])
				ret_string_pf(a, "+inf");
			else
				ret_string_pf(a, "+INF");
		}
		else if (a->obel_x[7])
			ret_string_pf(a, "inf");
		else
			ret_string_pf(a, "INF");
	}
	else if (a->obel_x[7])
		ret_string_pf(a, "-inf");
	else
		ret_string_pf(a, "-INF");
}

int		check_nan_pf(t_tab *a, double num)
{
	a->obel_x[7] = a->obel_x[10] % 2;
	if (num != num)
	{
		a->obel_x[8] = -1;
		if (a->obel_x[5] == 0)
			a->obel_x[5] = -1;
		if (a->obel_x[7])
			ret_string_pf(a, "nan");
		else
			ret_string_pf(a, "NAN");
		return (1);
	}
	if (num == (num * 10) && num)
	{
		a->obel_x[8] = -1;
		if (a->obel_x[5] == 0)
			a->obel_x[5] = -1;
		check_inf_pf(a, num);
		return (1);
	}
	return (0);
}

void	check_sig_pf(t_tab *a, long long int num)
{
	if (num < 0)
	{
		a->sym = '-';
		a->sig = 1;
	}
	if (num >= 0)
	{
		if (a->obel_x[4] == 1)
		{
			a->sym = ' ';
			a->sig = 1;
		}
		if (a->obel_x[4] == 2)
		{
			a->sym = '+';
			a->sig = 1;
		}
	}
}
