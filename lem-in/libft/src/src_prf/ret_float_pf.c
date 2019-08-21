/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_float_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:06:43 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:38:17 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*read_ts_p3_pf(t_tab *a)
{
	while (a->temp[0] == 'z')
	{
		a->obel_x[9] = 7;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	while (a->temp[0] == 't')
	{
		a->obel_x[9] = 8;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_ts_p4_pf(a));
	return (a);
}

t_tab	*read_ts_p4_pf(t_tab *a)
{
	a->count_b = 0;
	while (a->ty[a->count_b] != a->temp[0])
		a->count_b++;
	a->obel_x[10] = a->count_b + 1;
	ft_strcpy(a->temp, &(a->temp[1]));
	a = give_me_param_pf(a);
	a->abs_len += ft_strlen(a->temp);
	write(1, a->temp, ft_strlen(a->temp));
	if (a->temp)
	{
		free(a->temp);
		a->temp = NULL;
	}
	a->obel_x[2] = 7;
	return (a);
}

t_tab	*read_type_and_spec_pf(t_tab *a)
{
	while (a->temp[0] == 'l')
	{
		if (a->temp[1] == 'l')
		{
			a->obel_x[9] = 2;
			ft_strcpy(a->temp, &(a->temp[2]));
		}
		else
		{
			if (a->obel_x[9] != 2)
				a->obel_x[9] = 1;
			ft_strcpy(a->temp, &(a->temp[1]));
		}
	}
	while (a->temp[0] == 'L')
	{
		if (a->obel_x[9] < 1)
			a->obel_x[9] = 3;
		ft_strcpy(a->temp, &(a->temp[1]));
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (read_ts_p2_pf(a));
	return (a);
}

t_tab	*ret_char_pf(t_tab *a, char c)
{
	if (a->obel_x[6] < 2)
	{
		write(1, &c, 1);
		a->abs_len++;
		return (a);
	}
	zero_val_pf(a);
	if (a->obel_x[5] == 0)
	{
		zero_char_pf(a, c);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		char_left_al_pf(a, c);
		return (a);
	}
	other_char_pf(a, c);
	return (a);
}

t_tab	*ret_float_pf(t_tab *a, long double num)
{
	if (check_nan_pf(a, num))
		return (a);
	zero_val_pf(a);
	a->sym = 0;
	if (a->obel_x[4] == 1)
		a->sym = ' ';
	if (a->obel_x[4] == 2)
		a->sym = '+';
	if (num < 0)
	{
		a->sym = '-';
		num *= -1;
	}
	if (a->sym == '-' || a->sym == '+' || a->sym == ' ')
		a->sig = 1;
	if (a->obel_x[8] < 0)
		a->obel_x[8] = 6;
	itoa_float_pf(a, num);
	if (a->error == 1)
		return (memory_error_pf(a));
	put_itoa_float_pf(a);
	return (a);
}
