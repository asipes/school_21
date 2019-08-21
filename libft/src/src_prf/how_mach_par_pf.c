/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_mach_par_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:01:37 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:38:50 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*how_mach_par_pf(t_tab *a)
{
	a->error = 0;
	faster_faster_pf(a);
	while (a->form[a->count_a])
	{
		a->count_a = 1;
		a = clean_my_array_pf(a);
		if (a->form[0] == '%')
		{
			if (a->form[1] == '%')
				a->count_a = 2;
			else
				(a->obel_x[0] = 1);
		}
		else
			a->obel_x[0] = 0;
		while (a->form[a->count_a] != '%' && a->form[a->count_a])
			a->count_a++;
		a = feed_x_pf(a);
		if (a->error)
			return (a);
		a->count_a = 0;
	}
	return (a);
}

t_tab	*initialize_pf(t_tab *a)
{
	a->abs_len = 0;
	a->count_a = 0;
	a->parametr = 1;
	a->parametr_i = 0;
	a->parametr_f = 0;
	a->parametr_d = 0;
	a = array_of_param_pf(a);
	if (!(a->obel_x = (int *)malloc(sizeof(int) * 11)))
		return (memory_error_pf(a));
	a = how_mach_par_pf(a);
	if (a->error)
		return (a);
	return (a);
}

void	itoa_float_pf(t_tab *a, long double num)
{
	float_step1_pf(a, num);
	float_step2_pf(a);
	float_step3_pf(a, num);
	if (a->arr[0] == '0')
	{
		if ((int)a->tmp_b)
			ft_strcpy(a->arr, &a->arr[1]);
		a->len_num--;
	}
	a->len = 0;
	a->full = 0;
	a->zero = 0;
	a->stop = 0;
	a->space = 0;
	a->count_m = 0;
}

t_tab	*itoa_hex_pf(t_tab *a, unsigned long long int num)
{
	zero_val_pf(a);
	if (num != 0)
		hex_check_fl_pf(a);
	a->len_num = numlen_sig_pf(num, 16);
	if (num == 0 && a->obel_x[8] == 0)
	{
		hex_null_pf(a);
		return (0);
	}
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		hex_num_zero_pf(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		hex_left_al_pf(a, num);
		return (a);
	}
	other_hex_pf(a, num);
	return (a);
}

t_tab	*itoa_oct_pf(t_tab *a, unsigned long long int num)
{
	zero_val_pf(a);
	a->len_num = numlen_sig_pf(num, 8);
	if (a->obel_x[3] == 1 && num != 0)
	{
		a->sym = '0';
		a->sig = 1;
	}
	if (num == 0 && a->obel_x[8] == 0)
	{
		oct_null_pf(a);
		return (a);
	}
	if (a->obel_x[5] == 0 && a->obel_x[8] == -1)
	{
		oct_num_zero_pf(a, num);
		return (a);
	}
	if (a->obel_x[5] == 1)
	{
		oct_left_al_pf(a, num);
		return (a);
	}
	other_oct_pf(a, num);
	return (a);
}
