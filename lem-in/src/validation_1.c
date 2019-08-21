/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:48:06 by asipes            #+#    #+#             */
/*   Updated: 2019/08/08 13:58:35 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_atoi(char *str, unsigned long int ret, t_lem_in *a, int j)
{
	int	sign;

	sign = 1;
	if (str[j] == '-')
	{
		j++;
		sign = -1;
	}
	if (str[j] == '+' && sign == 1)
		j++;
	while (str[j] >= '0' && str[j] <= '9')
	{
		ret = ret * 10 + ((str[j]) - '0');
		j++;
		if ((sign == 1 && ret > 2147483647) ||
			(sign == -1 && ret > 2147483648))
		{
			ft_putstr("Error\n");
			lem_exit(0, a);
		}
	}
	return (ret * sign);
}

int		check_valid_connect(t_lem_in *a, int i, int trigger)
{
	a->run = a->c_beg;
	while (i < a->size_sc)
	{
		trigger = 0;
		if (a->run->flag == 6)
		{
			if (ft_strequ(a->run->name_fc, a->run->name_sc))
				return (1);
			trigger = support_cvc_f(a, 0);
			if (trigger == 1)
				trigger = support_cvc_s(a, 0);
			if (trigger != 2)
				return (1);
		}
		RUN;
		i++;
	}
	return (0);
}

int		support_cvc_f(t_lem_in *a, int j)
{
	a->run_r = a->r_beg;
	while (j < a->size_r)
	{
		if (ft_strequ(a->run_r->name, a->run->name_fc))
			return (1);
		RUN_R;
		j++;
	}
	return (0);
}

int		support_cvc_s(t_lem_in *a, int j)
{
	a->run_r = a->r_beg;
	while (j < a->size_r)
	{
		if (ft_strequ(a->run_r->name, a->run->name_sc))
			return (2);
		RUN_R;
		j++;
	}
	return (0);
}
