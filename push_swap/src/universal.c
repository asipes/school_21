/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:18:10 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 18:31:30 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	universal(void (*un_comm) (t_push *), char *str, t_push *ds)
{
	un_comm(ds);
	ds->temp_str = ds->str;
	ds->str = ft_strjoin(ds->str, str);
	ft_strdel(&ds->temp_str);
}
