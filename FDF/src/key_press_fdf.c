/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 22:07:45 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/01 13:30:39 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_sss_more_fdf(int keycode, t_fdfstr *a)
{
	if (keycode == 45)
		more_hight_fdf(a);
	else if (keycode == 11)
		many_hight_fdf(a);
	else if (keycode == 38)
		change_col_pres_fdf(a);
	else if (keycode == 40)
		change_c_h_pres_fdf(a);
}

void		key_ss_more_fdf(int keycode, t_fdfstr *a)
{
	if (keycode == 49)
		ret_stock_fdf(a);
	else if (keycode == 28)
		more_r_col_h_fdf(a);
	else if (keycode == 32)
		many_r_col_h_fdf(a);
	else if (keycode == 25)
		more_g_col_h_fdf(a);
	else if (keycode == 34)
		many_g_col_h_fdf(a);
	else if (keycode == 29)
		more_b_col_h_fdf(a);
	else if (keycode == 31)
		many_b_col_h_fdf(a);
	else if (keycode == 24 || keycode == 69)
		more_map_size_fdf(a);
	else if (keycode == 27 || keycode == 78)
		many_map_size_fdf(a);
	else
		key_sss_more_fdf(keycode, a);
}

void		key_some_more_fdf(int keycode, t_fdfstr *a)
{
	if (keycode == 18)
		see_norm_fdf(a);
	else if (keycode == 19)
		see_iso_fdf(a);
	else if (keycode == 20)
		see_top_fdf(a);
	else if (keycode == 21)
		see_nice_fdf(a);
	else if (keycode == 41 || keycode == 76)
		centrol_fdf(a);
	else if (keycode == 15)
		more_r_color_fdf(a);
	else if (keycode == 3)
		many_r_color_fdf(a);
	else if (keycode == 17)
		more_g_color_fdf(a);
	else if (keycode == 5)
		many_g_color_fdf(a);
	else if (keycode == 16)
		more_b_color_fdf(a);
	else if (keycode == 4)
		many_b_color_fdf(a);
	else
		key_ss_more_fdf(keycode, a);
}

void		key_next_fdf(int keycode, t_fdfstr *a)
{
	if ((keycode == 256 || keycode == 269 || keycode == 46) && a->mod_step > 1)
		many_step_fdf(a);
	else if (keycode == 257 || keycode == 258 || keycode == 43)
		more_step_fdf(a);
	else if (keycode == 1 || keycode == 87)
		centrolize_fdf(a);
	else if (keycode == 126 || keycode == 35)
		more_betta_fdf(a);
	else if (keycode == 125 || keycode == 44)
		many_betta_fdf(a);
	else if (keycode == 123 || keycode == 37)
		many_gamma_fdf(a);
	else if (keycode == 124 || keycode == 39)
		more_gamma_fdf(a);
	else if (keycode == 82 || keycode == 47)
		many_cetta_fdf(a);
	else if (keycode == 65 || keycode == 33)
		more_cetta_fdf(a);
	else
		key_some_more_fdf(keycode, a);
}

int			key_press_fdf(int keycode, t_fdfstr *a)
{
	if (keycode == 53)
		say_good_buy_fdf(a);
	else if (keycode == 13 || keycode == 91)
		map_top_fdf(a);
	else if (keycode == 7 || keycode == 84)
		map_down_fdf(a);
	else if (keycode == 0 || keycode == 86)
		map_left_fdf(a);
	else if (keycode == 2 || keycode == 88)
		map_right_fdf(a);
	else if (keycode == 12 || keycode == 89)
		map_lt_fdf(a);
	else if (keycode == 14 || keycode == 92)
		map_rt_fdf(a);
	else if (keycode == 8 || keycode == 85)
		map_rd_fdf(a);
	else if (keycode == 6 || keycode == 83)
		map_ld_fdf(a);
	else
		key_next_fdf(keycode, a);
	return (0);
}
