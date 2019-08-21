/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:36:51 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/02 17:11:29 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include "math.h"

typedef struct			s_fdf_main
{
	char				*str;
	char				*stl;
	void				*bs_list;
	int					**arr;
	int					c_a;
	int					c_b;
	int					c_c;
	int					c_d;
	int					c_x;
	int					c_y;
	int					c_str;
	int					c_par;
	int					c_stl;
	int					b_x1;
	int					b_x2;
	int					b_y1;
	int					b_y2;
	double				b_col_per;
	double				x1;
	double				y1;
	double				z1;
	int					b_col_st;
	int					b_col_go;
	int					b_col_end;
	int					b_col_rst;
	int					b_col_gst;
	int					b_col_bst;
	int					b_delta_x;
	int					b_delta_y;
	int					b_sign_x;
	int					b_sign_y;
	int					b_err1;
	int					b_err2;
	int					fd;
	int					gnl;
	int					mod_size;
	int					mod_color;
	int					mod_col_h;
	int					s_x;
	double				alfa;
	double				betta;
	double				gamma;
	double				cetta;
	int					gg;
	int					jj;
	double				dd;
	int					s_y;
	int					size_win_x;
	int					size_win_y;
	int					mod_step;
	int					touch_1;
	int					touch_2;
	int					touch_3;
	int					touch_4;
	int					last_x1;
	int					last_y1;
	int					last_x2;
	int					last_y2;
	int					bpp;
	int					stride;
	int					endian;
	long double			pi;
	int					mod_see;
	double				mod_hight;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*im2_ptr;
	double				max_z;
	double				min_z;
}						t_fdfstr;

typedef struct			s_fdf_read
{
	char				*str;
	struct s_fdf_read	*next;
}						t_fdfread;

int						read_map_fdf(t_fdfstr *a);
t_fdfread				*new_list_fdf();

int						calk_params2_fdf(t_fdfstr *a, t_fdfread *newl);
int						read_strukt_fdf(t_fdfstr *a, t_fdfread *newl);
int						read_param_fdf(t_fdfstr *a, t_fdfread *newl);
void					find_digit_fdf(t_fdfstr *a, t_fdfread *newl);

void					check_hex_fdf(t_fdfstr *a, t_fdfread *newl);
void					read_hex_fdf(t_fdfstr *a, t_fdfread *newl);

int						clean_list_fdf(t_fdfstr *a, t_fdfread *newl);
void					optimizate_line_fdf(t_fdfstr *a);

void					gevi_me_line_fdf(t_fdfstr *a);
void					give_me_line_p2_fdf(t_fdfstr *a);
void					calc_color_step_fdf(t_fdfstr *a);
void					calc_col_step_p2_fdf(t_fdfstr *a);
void					color_zero_fdf(t_fdfstr *a);

void					paint_line_fdf(t_fdfstr *a);
void					change_color_fdf(t_fdfstr *a);
int						r_fdf(double x);
void					lead_up_for_paint_fdf(t_fdfstr *a);

int						paint_map_fdf(t_fdfstr *a);
void					camera_mod_1_fdf(t_fdfstr *a);
void					camera_mod_2_fdf(t_fdfstr *a);
void					camera_mod_3_fdf(t_fdfstr *a);
void					camera_mod_4_fdf(t_fdfstr *a);

void					info_window_fdf(t_fdfstr *a);
void					more_info_fdf(t_fdfstr *a);
void					some_info_fdf(t_fdfstr *a);
void					s2_info_fdf(t_fdfstr *a);
void					s3_info_fdf(t_fdfstr *a);

void					text_fdf(t_fdfstr *a, int j, char *str);
void					t_fdf(t_fdfstr *a, char *str, char *stl);
void					t1_fdf(t_fdfstr *a, char *str, char *stl);

int						key_press_fdf(int keycode, t_fdfstr *a);
void					key_next_fdf(int keycode, t_fdfstr *a);
void					key_some_more_fdf(int keycode, t_fdfstr *a);
void					key_ss_more_fdf(int keycode, t_fdfstr *a);
void					key_sss_more_fdf(int keycode, t_fdfstr *a);

void					many_b_color_fdf(t_fdfstr *a);
void					more_b_color_fdf(t_fdfstr *a);
void					many_g_color_fdf(t_fdfstr *a);
void					more_g_color_fdf(t_fdfstr *a);
void					many_r_color_fdf(t_fdfstr *a);

void					more_r_color_fdf(t_fdfstr *a);
void					many_step_fdf(t_fdfstr *a);
void					more_step_fdf(t_fdfstr *a);
void					map_left_fdf(t_fdfstr *a);
void					map_right_fdf(t_fdfstr *a);

void					map_top_fdf(t_fdfstr *a);
void					map_down_fdf(t_fdfstr *a);
void					many_map_size_fdf(t_fdfstr *a);
void					more_map_size_fdf(t_fdfstr *a);

void					more_hight_fdf(t_fdfstr *a);
void					many_hight_fdf(t_fdfstr *a);
void					more_cetta_fdf(t_fdfstr *a);
void					many_cetta_fdf(t_fdfstr *a);
void					more_gamma_fdf(t_fdfstr *a);

void					many_gamma_fdf(t_fdfstr *a);
void					more_betta_fdf(t_fdfstr *a);
void					many_betta_fdf(t_fdfstr *a);
void					more_alfa_fdf(t_fdfstr *a);
void					many_alfa_fdf(t_fdfstr *a);

void					see_iso_fdf(t_fdfstr *a);
void					see_top_fdf(t_fdfstr *a);
void					see_nice_fdf(t_fdfstr *a);
void					see_norm_fdf(t_fdfstr *a);

int						say_good_buy_fdf(t_fdfstr *a);
void					calk_mouse1_move_fdf(int x, int y, t_fdfstr *a);
void					calk_mouse2_move_fdf(int x, int y, t_fdfstr *a);
void					more_cetta_m_fdf(t_fdfstr *a);
void					many_cetta_m_fdf(t_fdfstr *a);

int						test_anton_fdf(t_fdfstr *a);

void					go_go_to_start_fdf(t_fdfstr *a);
void					go_go_calk_now_fdf(t_fdfstr *a);
void					calk_map_fdf(t_fdfstr *a);
int						ch_fdf(t_fdfstr *a, int i);
void					ch2_fdf(t_fdfstr *a);

int						mouse_press_fdf(int mc, int x, int y, t_fdfstr *a);
int						mouse_dont_press_fdf(int mc, int x, int y, t_fdfstr *a);
int						mouse_go_fdf(int x, int y, t_fdfstr *a);

void					color_preset_fdf(t_fdfstr *a);
void					more_preset1_fdf(t_fdfstr *a);
void					more_preset2_fdf(t_fdfstr *a);
void					more_preset3_fdf(t_fdfstr *a);
void					more_preset4_fdf(t_fdfstr *a);

void					more_preset5_fdf(t_fdfstr *a);
void					more_preset6_fdf(t_fdfstr *a);
void					more_preset7_fdf(t_fdfstr *a);
void					more_preset8_fdf(t_fdfstr *a);
void					more_preset9_fdf(t_fdfstr *a);

void					more_preset10_fdf(t_fdfstr *a);
void					more_preset11_fdf(t_fdfstr *a);
void					more_preset12_fdf(t_fdfstr *a);

void					color_pres_h_fdf(t_fdfstr *a);
void					more_pres_h1_fdf(t_fdfstr *a);
void					more_pres_h2_fdf(t_fdfstr *a);
void					more_pres_h3_fdf(t_fdfstr *a);
void					more_pres_h4_fdf(t_fdfstr *a);

void					more_pres_h5_fdf(t_fdfstr *a);
void					more_pres_h6_fdf(t_fdfstr *a);
void					more_pres_h7_fdf(t_fdfstr *a);
void					more_pres_h8_fdf(t_fdfstr *a);
void					more_pres_h9_fdf(t_fdfstr *a);

void					more_pres_h10_fdf(t_fdfstr *a);
void					more_pres_h11_fdf(t_fdfstr *a);
void					more_pres_h12_fdf(t_fdfstr *a);

void					ret_stock_fdf(t_fdfstr *a);

void					calk_parametrs_fdf(t_fdfstr *a);

void					map_lt_fdf(t_fdfstr *a);
void					map_rt_fdf(t_fdfstr *a);
void					map_ld_fdf(t_fdfstr *a);
void					map_rd_fdf(t_fdfstr *a);

void					centrolize_fdf(t_fdfstr *a);
void					centrol_fdf(t_fdfstr *a);
void					more_g_col_h_fdf(t_fdfstr *a);
void					many_g_col_h_fdf(t_fdfstr *a);

void					more_r_col_h_fdf(t_fdfstr *a);
void					many_r_col_h_fdf(t_fdfstr *a);
void					more_b_col_h_fdf(t_fdfstr *a);
void					many_b_col_h_fdf(t_fdfstr *a);

void					change_col_pres_fdf(t_fdfstr *a);
void					change_c_h_pres_fdf(t_fdfstr *a);

#endif
