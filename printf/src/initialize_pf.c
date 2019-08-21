/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:26:25 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/04/29 14:13:20 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab		*memory_error_pf(t_tab *a)
{
	a->error = 1;
	return (a);
}

t_tab		*clean_my_array_pf(t_tab *a)
{
	a->count_b = 0;
	while (a->count_b < 12)
	{
		a->obel_x[a->count_b] = -1;
		a->count_b++;
	}
	return (a);
}

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

t_tab		*how_mach_par_pf(t_tab *a)
{
	a->error = 0;
	while (a->form[a->count_a])
	{
		a->count_a = 1;
		a = clean_my_array_pf(a);
		if (a->form[0] == '%')
		{
			if (a->form[1] == '%')
				a->count_a = 2;
			else
				(a->obel_x[0] = 1);
		}
		else
			a->obel_x[0] = 0;
		while (a->form[a->count_a] != '%' && a->form[a->count_a])
			a->count_a++;
		a = feed_x_pf(a);
		if (a->error)
			return (a);
	}
	return (a);
}

t_tab		*initialize_pf(t_tab *a)
{
	a->abs_len = 0;
	a->count_a = 0;
	a->parametr = 1;
	a->parametr_i = 0;
	a->parametr_f = 0;
	a->parametr_d = 0;
	a = array_of_param_pf(a);
	if (!(a->obel_x = (int *)malloc(sizeof(int) * 11)))
		return (memory_error_pf(a));
	a = how_mach_par_pf(a);
	if (a->error)
		return (a);
	return (a);
}
