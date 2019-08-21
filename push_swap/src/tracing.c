/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:18:06 by asipes            #+#    #+#             */
/*   Updated: 2019/07/20 18:13:38 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tracing(t_push *ds, char *src)
{
	ds->temp_str = ds->str;
	ds->str = ft_strjoin(ds->str, src);
	ft_strdel(&ds->temp_str);
	ds->temp_str = ds->str;
	ds->str = ft_strjoin(ds->str, " ");
	ft_strdel(&ds->temp_str);
}

int		ps_atoi(t_push *ds, unsigned int ret, int sign)
{
	while ((ds->str[ds->j] >= 9 && ds->str[ds->j] <= 13) ||
			ds->str[ds->j] == 32 || ds->str[ds->j] == ',')
		ds->j++;
	if (ds->str[ds->j] == '-')
	{
		ds->j++;
		sign = -1;
	}
	if (ds->str[ds->j] == '+' && sign == 1)
		ds->j++;
	while (ds->str[ds->j] >= '0' && ds->str[ds->j] <= '9')
	{
		ret = ret * 10 + ((ds->str[ds->j]) - '0');
		ds->j++;
		if ((sign == 1 && ret > 2147483647) ||
			(sign == -1 && ret > 2147483648))
		{
			ft_putstr("Error\n");
			exit(0);
		}
	}
	return (ret * sign);
}
