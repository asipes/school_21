/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_valid_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:22:08 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 16:56:58 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_tab		*no_valid_pf(t_tab *a)
{
	a->p_char = a->temp[0];
	a = ret_char_pf(a, a->p_char);
	ft_strcpy(a->temp, &(a->temp[1]));
	if (a->temp[0])
	{
		a->abs_len += ft_strlen(a->temp);
		write(1, a->temp, ft_strlen(a->temp));
	}
	free(a->temp);
	a->temp = NULL;
	return (a);
}
