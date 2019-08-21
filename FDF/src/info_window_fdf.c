/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_window_fdf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 22:05:38 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/01 15:10:01 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		s3_info_fdf(t_fdfstr *a)
{
	a->c_c += 20;
	a->c_b = 0xFF00FF;
	a->str = ft_itoa(r_fdf(a->betta * 180 / a->pi));
	text_fdf(a, a->size_win_x - 85, a->str);
	free(a->str);
	t1_fdf(a, "'2'", "for Iso");
	a->c_c += 20;
	a->str = ft_itoa(r_fdf(a->gamma * 180 / a->pi));
	text_fdf(a, a->size_win_x - 85, a->str);
	free(a->str);
	t1_fdf(a, "'3'", "for Top");
	a->c_c += 20;
	t1_fdf(a, "'4'", "for Face");
	a->str = ft_itoa(r_fdf(a->cetta * 180 / a->pi));
	text_fdf(a, a->size_win_x - 85, a->str);
	free(a->str);
}

void		s2_info_fdf(t_fdfstr *a)
{
	a->c_c += 20;
	text_fdf(a, a->size_win_x - 310, "'K' - change Top  color preset");
	t_fdf(a, "'Space'", "return start value");
	a->c_c = a->size_win_y - 40;
	a->c_b = 0xFF0000;
	text_fdf(a, 20, "'Np_1' 'Np_2' 'Np_3' 'Np_4' 'Np_6' 'Np_7' 'Np_8' 'Np_9'");
	text_fdf(a, a->size_win_x - 370, "'left-right' 'top-down' 'Np_0-Np_.'");
	a->c_c -= 20;
	text_fdf(a, 20, "'Z' 'X' 'C' 'A' 'D' 'Q' 'W' 'E'");
	text_fdf(a, a->size_win_x - 300, "'left_mouse + move' 'scroll'");
	a->c_c -= 20;
	text_fdf(a, 20, "'right_mouse + move'");
	text_fdf(a, a->size_win_x - 250, "'L' '\"' 'P' '?' '>' '}'");
	a->c_c -= 20;
	a->c_b = 0x00FF00;
	text_fdf(a, 20, "Change coordinates:");
	text_fdf(a, a->size_win_x - 150, "Change angle:");
	a->c_c = a->size_win_y / 2 - 40;
	a->c_b = 0xFFFFFF;
	t1_fdf(a, "'1'", "for Normal");
	text_fdf(a, a->size_win_x - 85, "Angles:");
	s3_info_fdf(a);
}

void		some_info_fdf(t_fdfstr *a)
{
	a->c_c += 20;
	t_fdf(a, "'-' or '+'", "(- / +) Map ZOOM. Now zoom:");
	a->str = ft_itoa(a->mod_size);
	text_fdf(a, 440, a->str);
	free(a->str);
	text_fdf(a, a->size_win_x - 405, "(F/R) (G/T)");
	text_fdf(a, a->size_win_x - 279, "(H/Y)        (I/9)");
	text_fdf(a, a->size_win_x - 88, "(O/0)");
	text_fdf(a, a->size_win_x - 205, "(U/8)");
	a->c_c += 20;
	text_fdf(a, a->size_win_x - 387, "For '-' or '+' any color parametr");
	t_fdf(a, "'B' or 'N'", "(- / +) Change HIGHT. Now hight:");
	a->str = ft_itoa(r_fdf(a->mod_hight * 10));
	a->stl = ft_strjoin(a->str, "/10");
	text_fdf(a, 490, a->stl);
	free(a->str);
	free(a->stl);
	a->c_c += 20;
	t_fdf(a, "'S' or 'Np5'", "return mid coordinates");
	a->c_c += 20;
	text_fdf(a, a->size_win_x - 310, "'J' - change Down color preset");
	t_fdf(a, "';' or 'Np_Ent'", "return start angle");
	s2_info_fdf(a);
}

void		more_info_fdf(t_fdfstr *a)
{
	a->str = ft_itoa(a->mod_color >> 16);
	text_fdf(a, a->size_win_x - 395, a->str);
	free(a->str);
	a->str = ft_itoa(a->mod_col_h >> 16);
	text_fdf(a, a->size_win_x - 195, a->str);
	free(a->str);
	a->str = ft_itoa(a->mod_color >> 8 & 0xFF);
	text_fdf(a, a->size_win_x - 334, a->str);
	free(a->str);
	a->str = ft_itoa(a->mod_col_h >> 8 & 0xFF);
	text_fdf(a, a->size_win_x - 139, a->str);
	free(a->str);
	a->str = ft_itoa(a->mod_color & 0xFF);
	text_fdf(a, a->size_win_x - 269, a->str);
	free(a->str);
	a->str = ft_itoa(a->mod_col_h & 0xFF);
	text_fdf(a, a->size_win_x - 79, a->str);
	free(a->str);
	t_fdf(a, "'M' or '<'", "(- / +) STEP for oter parametrs. Now step:");
	a->str = ft_itoa(a->mod_step);
	text_fdf(a, 590, a->str);
	free(a->str);
	some_info_fdf(a);
}

void		info_window_fdf(t_fdfstr *a)
{
	a->c_b = 0xFFFFFF;
	a->c_c = 10;
	text_fdf(a, 20, "Please, read this before do anything, thank!");
	a->c_b = a->mod_color;
	text_fdf(a, a->size_win_x - 400, "Change Down color");
	a->c_b = a->mod_col_h;
	text_fdf(a, a->size_win_x - 200, "Change Top color");
	a->c_c += 20;
	a->c_b = 0xFF0000;
	text_fdf(a, a->size_win_x - 395, "Red");
	text_fdf(a, a->size_win_x - 195, "Red");
	a->c_b = 0x00FF00;
	text_fdf(a, a->size_win_x - 345, "Green");
	text_fdf(a, a->size_win_x - 150, "Green");
	a->c_b = 0x0000FF;
	text_fdf(a, a->size_win_x - 275, "Blue");
	text_fdf(a, a->size_win_x - 85, "Blue");
	t_fdf(a, "'Esk'", "for EXIT");
	a->c_b = 0xFFFFFF;
	a->c_c += 20;
	more_info_fdf(a);
}
