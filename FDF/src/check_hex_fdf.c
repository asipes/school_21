/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hex_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:41 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/27 17:22:58 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_hex_fdf(t_fdfstr *a, t_fdfread *newl)
{
	while (ft_isdigit(newl->str[a->c_c]) || (newl->str[a->c_c] >= 'a'
			&& newl->str[a->c_c] <= 'f') || (newl->str[a->c_c] >= 'A'
			&& newl->str[a->c_c] <= 'F'))
	{
		if (ft_isdigit(newl->str[a->c_c]))
			a->c_d = newl->str[a->c_c] - '0';
		else if (newl->str[a->c_c] < 'Z')
			a->c_d = newl->str[a->c_c] - 'A' + 10;
		else
			a->c_d = newl->str[a->c_c] - 'a' + 10;
		a->arr[a->c_par - 1][3] += a->c_b * a->c_d;
		a->c_c--;
		a->c_b *= 16;
	}
}

void	check_hex_fdf(t_fdfstr *a, t_fdfread *newl)
{
	a->arr[a->c_par - 1][3] = 0;
	if (newl->str[a->c_a] && newl->str[a->c_a + 1] && newl->str[a->c_a] == '0'
			&& (newl->str[a->c_a + 1] == 'x' || newl->str[a->c_a + 1]))
	{
		a->c_a += 2;
		while (newl->str[a->c_a] && (ft_isdigit(newl->str[a->c_a]) ||
				(newl->str[a->c_a] >= 'a' && newl->str[a->c_a] <= 'f') ||
				(newl->str[a->c_a] >= 'A' && newl->str[a->c_a] <= 'F')))
			a->c_a++;
		a->c_a--;
		a->c_c = a->c_a;
		a->c_b = 1;
		read_hex_fdf(a, newl);
		if (a->arr[a->c_par - 1][3] < 0 || a->arr[a->c_par - 1][3] > 0xFFFFFF)
			a->arr[a->c_par - 1][3] = -1;
	}
}
