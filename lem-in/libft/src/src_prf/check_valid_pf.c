/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:01 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:39:23 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*check_valid_pf(t_tab *a)
{
	while (a->temp)
	{
		if (!(a->temp[0]) && *a->form == '%')
			return (percent_type_pf(a));
		if (!(a->temp[0]))
		{
			free(a->temp);
			return (a);
		}
		a->count_a = 0;
		while (a->temp[0] != a->tf[a->count_a] && a->tf[a->count_a]
				&& a->temp[0])
			a->count_a++;
		if (a->tf[a->count_a] && a->temp[0])
			a = hard_check_pf(a);
		else
			return (no_valid_pf(a));
		if (a->obel_x[2] == 7)
			return (a);
	}
	return (a);
}

t_tab	*clean_my_array_pf(t_tab *a)
{
	a->count_b = 0;
	while (a->count_b < 12)
	{
		a->obel_x[a->count_b] = -1;
		a->count_b++;
	}
	return (a);
}

t_tab	*duck_star_pf(t_tab *a)
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

t_tab	*exit_pf(t_tab *a)
{
	if (a)
	{
		if (a->obel_x)
			free(a->obel_x);
		if (a->form)
			free(a->form);
		if (a->fl)
			free(a->fl);
		if (a->ty)
			free(a->ty);
		if (a->tf)
			free(a->tf);
		free(a);
	}
	return (a);
	a = NULL;
}

void	faster_faster_pf(t_tab *a)
{
	a->count_c = 0;
	while (a->form[a->count_c] && a->form[a->count_c] != '%')
	{
		if (a->count_c == 200)
		{
			write(1, a->form, a->count_c);
			a->form = ft_strcpy(a->form, &(a->form[a->count_c]));
			a->abs_len += a->count_c;
			a->count_c = 0;
		}
		a->count_c++;
	}
	write(1, a->form, a->count_c);
	a->abs_len += a->count_c;
	a->form = ft_strcpy(a->form, &(a->form[a->count_c]));
	a->count_c = 0;
}
