/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:36:51 by asipes            #+#    #+#             */
/*   Updated: 2019/05/25 17:12:01 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
