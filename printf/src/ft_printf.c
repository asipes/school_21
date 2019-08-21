/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:36:51 by asipes            #+#    #+#             */
/*   Updated: 2019/04/29 20:37:27 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int		ft_printf(char *format, ...)
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
