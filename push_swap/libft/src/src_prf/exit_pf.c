/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:29:15 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 08:29:31 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
