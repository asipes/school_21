/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:48:17 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/27 17:34:47 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdfread		*new_list_fdf(void)
{
	t_fdfread	*newl;

	if (!(newl = (t_fdfread *)malloc(sizeof(t_fdfread))))
		return (NULL);
	newl->str = NULL;
	newl->next = NULL;
	return (newl);
}

int				read_map_fdf(t_fdfstr *a)
{
	t_fdfread	*newl;

	if (!(newl = new_list_fdf()))
		return (1);
	a->bs_list = newl;
	a->c_str = 0;
	while ((a->gnl = get_next_line(a->fd, &(newl->str))) != 0)
	{
		if (a->gnl < 0 || (!(newl->next = new_list_fdf())))
			return (1);
		newl = newl->next;
		a->c_str++;
	}
	close(a->fd);
	newl = a->bs_list;
	if (!(newl->str))
		return (0);
	return (calk_params2_fdf(a, newl));
}
