/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlen_sig_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 22:01:58 by asipes            #+#    #+#             */
/*   Updated: 2019/05/19 10:19:04 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
