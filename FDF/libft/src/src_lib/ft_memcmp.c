/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:03:12 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 13:08:20 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*ar1;
	unsigned char	*ar2;

	ar1 = (unsigned char *)arr1;
	ar2 = (unsigned char *)arr2;
	if (n == 0)
		return (0);
	while (n - 1)
	{
		if (*ar1 != *ar2)
			return (*ar1 - *ar2);
		ar1++;
		ar2++;
		n--;
	}
	return (*ar1 - *ar2);
}
