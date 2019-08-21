/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:36:51 by asipes            #+#    #+#             */
/*   Updated: 2019/07/21 13:39:02 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(char *format, ...)
{
	t_tab	*a;
	size_t	i;

	if (!(format) || !(format[0]))
		return (0);
	a = NULL;
	if (!(a = (t_tab *)malloc(sizeof(t_tab))) ||
			!(a->form = ft_strdup(format)))
	{
		exit_pf(a);
		return (-1);
	}
	va_start(a->ap, format);
	a = initialize_pf(a);
	if (a->error)
	{
		exit_pf(a);
		return (-1);
	}
	va_end(a->ap);
	i = a->abs_len;
	exit_pf(a);
	return (i);
}

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

t_tab		*hard_check_p3_pf(t_tab *a)
{
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
		a->obel_x[8] = a->int_temp >= 0 ? a->int_temp : -1;
	}
	return (hard_check_p3_pf(a));
}

void		hex_chec_len_pf(t_tab *a)
{
	a->zero = a->obel_x[8] - a->len_num;
	if (a->zero < 0)
		a->zero = 0;
	a->space = a->obel_x[6] - (a->len_num + a->zero + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->zero + a->len_num + a->space;
}
