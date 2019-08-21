/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_al_var_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 09:56:56 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 13:38:38 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			left_al_var_pf(t_tab *a)
{
	a->zero = a->obel_x[8] - a->len_num;
	if (a->zero < 0)
		a->zero = 0;
	a->space = a->obel_x[6] - (a->len_num + a->zero + a->sig);
	if (a->space < 0)
		a->space = 0;
	a->len = a->sig + a->zero + a->len_num + a->space;
}

t_tab			*memory_error_pf(t_tab *a)
{
	a->error = 1;
	return (a);
}

t_tab			*no_valid_pf(t_tab *a)
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

long long int	non_uns_int_pf(t_tab *a, long long int i)
{
	if (a->obel_x[10] == 2)
		return (i);
	if (a->obel_x[9] == -1)
		i = (int)i;
	if (a->obel_x[9] == 1)
		i = (long int)i;
	if (a->obel_x[9] == 3)
		i = (int)i;
	if (a->obel_x[9] == 4)
		i = (short int)i;
	if (a->obel_x[9] == 5)
		i = (char)i;
	if (a->obel_x[9] == 7)
		i = (size_t)i;
	return (i);
}

void			num_zero_left_pf(t_tab *a)
{
	a->space = a->obel_x[6] - a->sig;
	if (a->space < 0)
		a->space = 0;
	a->len = a->space + a->sig;
	a->mass = ft_strnew(a->len);
	a->abs_len += a->len;
	if (a->obel_x[4] >= 1)
	{
		a->mass[a->count_m] = a->sym;
		a->count_m++;
	}
	a->stop = a->len;
	put_space_pf(a);
	write(1, a->mass, a->len);
	free(a->mass);
}
