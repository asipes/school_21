/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_param_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:20:06 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 15:06:52 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*array_of_param_pf(t_tab *a)
{
	if (!(a->ty = ft_strdup("dDioOuxXfFeEgGaAcCsSpnU")) ||
			!(a->fl = ft_strdup(" +-#0lhjztL123456789.*")) ||
			!(a->tf = ft_strjoin(a->fl, a->ty)))
		return (memory_error_pf(a));
	return (a);
}
