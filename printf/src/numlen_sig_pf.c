/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlen_sig_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asipes <asipes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 22:01:58 by asipes            #+#    #+#             */
/*   Updated: 2019/04/29 21:12:09 by asipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		numlen_sig_pf(unsigned long long int num, size_t base)
{
	int	len;

	len = 1;
	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
