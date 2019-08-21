/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faster_faster_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:29:44 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 18:50:05 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			faster_faster_pf(t_tab *a)
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
