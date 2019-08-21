/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_type_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:27:00 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 16:56:57 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*percent_type_pf(t_tab *a)
{
	free(a->temp);
	a->count_a = 1;
	while (a->form[a->count_a] && a->form[a->count_a] != '%')
		a->count_a++;
	if ((a->form[a->count_a] &&
			!(a->temp = ft_strsub(a->form, 0, a->count_a - 1))))
		return (memory_error_pf(a));
	if ((!(a->form[a->count_a]) &&
			!(a->temp = ft_strsub(a->form, 0, a->count_a))))
		return (memory_error_pf(a));
	a->form = ft_strcpy(a->form, &(a->form[a->count_a]));
	return (no_valid_pf(a));
}
