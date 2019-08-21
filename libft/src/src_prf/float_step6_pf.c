/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_step6_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:11:18 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:39:07 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	float_step6_pf(t_tab *a)
{
	if ((a->tmp_a > 0.5) || (a->tmp_a >= 0.5 && a->int_max % 2))
	{
		a->int_max++;
		a->count_m--;
		if (a->int_max < 10)
			a->arr[a->count_m] = a->int_max + '0';
		while (a->int_max == 10)
		{
			a->arr[a->count_m] = '0';
			a->count_m--;
			if (a->arr[a->count_m] == '.')
				a->count_m--;
			a->int_max = a->arr[a->count_m] - '0';
			a->int_max++;
			if (a->int_max > 0 && a->int_max < 9)
				a->arr[a->count_m] = a->int_max + '0';
		}
	}
}

void	ft_other_opt_p_pf(t_tab *a, long long int num)
{
	if (num == 0 && a->obel_x[8] == 0)
	{
		a->len = 0;
		if (a->obel_x[4] == 1 && a->sym == '+' && a->obel_x[6] > 0)
		{
			write(1, " ", 1);
			a->abs_len++;
		}
	}
	if (num == 0 && a->obel_x[8] != 0)
		write(1, "0", 1);
}

void	ft_other_opt_pf(t_tab *a, long long int num)
{
	a->space = a->obel_x[6] - a->len;
	a->zero = a->obel_x[8] - a->len;
	if (a->zero > 0)
		a->space -= a->zero;
	if (a->sym == '-' || a->obel_x[4] == 2)
		a->space--;
	if (a->space > 0)
		while (a->space--)
		{
			write(1, " ", 1);
			a->abs_len++;
		}
	if (a->sym == '-' || a->obel_x[4] == 2)
	{
		write(1, &(a->sym), 1);
		a->abs_len++;
	}
	if (a->zero > 0)
		while (a->zero--)
		{
			write(1, "0", 1);
			a->abs_len++;
		}
	ft_other_opt_p_pf(a, num);
}

t_tab	*give_me_param_pf(t_tab *a)
{
	va_list	cap;

	va_copy(cap, a->ap);
	a = fing_my_param_pf(a, cap);
	if (a->obel_x[10] > 8 && a->obel_x[10] < 17 && a->obel_x[9] != 3)
	{
		a->count_b = 1 + a->parametr_i + a->parametr_d;
		while (a->count_b < a->parametr)
		{
			a->p_float = va_arg(cap, double);
			a->count_b++;
		}
		a->parametr_f = a->parametr - a->parametr_i - a->parametr_d;
	}
	a->parametr++;
	a->p_float = 0;
	a->p_double = 0;
	a->int_temp = 0;
	a = junction_pf(cap, a);
	va_end(cap);
	return (a);
}

t_tab	*hard_check_p1_pf(t_tab *a)
{
	if (ft_isdigit(a->temp[0]))
	{
		a->int_temp = ft_atoi(a->temp);
		while (ft_isdigit(a->temp[0]))
			ft_strcpy(a->temp, &(a->temp[1]));
		if (a->temp[0] == '$')
		{
			a->parametr = a->int_temp;
			ft_strcpy(a->temp, &(a->temp[1]));
		}
		else
			a->obel_x[6] = a->int_temp;
	}
	while (a->temp[0] == '*')
	{
		a = duck_star_pf(a);
		a->obel_x[5] = a->int_temp < 0 ? 1 : a->obel_x[5];
		a->obel_x[6] = a->int_temp > 0 ? a->int_temp : -1 * a->int_temp;
	}
	if (a->temp[0] == a->tf[a->count_a])
		return (hard_check_p2_pf(a));
	return (a);
}
