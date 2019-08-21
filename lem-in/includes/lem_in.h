/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:36:51 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/08/08 16:18:20 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "mlx.h"
# include "math.h"
# include <pthread.h>
# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define RUN a->run = a->run->next
# define RUN_R a->run_r = a->run_r->next

typedef struct			s_cells
{
	char				*str;
	char				*name;
	char				*name_fc;
	char				*name_sc;
	char				*x_pos;
	char				*y_pos;
	char				*tmp;
	int					flag;
	struct s_cells		*next;
}						t_cells;

typedef struct			s_rooms
{
	char				*name;
	int					x_pos;
	int					y_pos;
	int					ord;
	int					numb;
	int					check;
	struct s_rooms		*e_room;
	struct s_rooms		*p_room;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_way
{
	int					*way;
	int					size;
}						t_way;

typedef struct			s_combo
{
	t_way				**ways;
	int					n_way;
	struct s_combo		*next;
	struct s_combo		*prew;
}						t_combo;

typedef struct			s_vis
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr_m;
	void				*img_adr_m;
	void				*img_ptr_a;
	void				*img_adr_a;
	int					**rooms;
	int					**ants;
	int					r_line;
	int					r_st;
	int					w_x;
	int					w_y;
	int					w_z;
	int					a_x;
	int					a_y;
	int					size;
	int					mid;
	int					bpp;
	int					stride;
	int					endian;
	int					ca;
	int					cb;
	int					cc;
	int					cd;
	int					ce;
	int					fd;
	int					b_delta_x;
	int					b_x2;
	int					b_x1;
	int					b_delta_y;
	int					b_y2;
	int					b_y1;
	int					b_sign_x;
	int					b_sign_y;
	int					b_err1;
	int					b_err2;
	int					color;
}						t_vis;

typedef struct			s_lem_in
{
	t_vis				*v;
	t_cells				*c_beg;
	t_cells				*run;
	t_cells				*tmp;
	t_rooms				*r_beg;
	t_rooms				*run_r;
	t_rooms				**rooms;
	t_combo				*w_beg;
	t_combo				*w_run;
	pthread_t			thread;
	int					sv;
	int					status;
	int					status_addr;
	int					*array_ways;
	int					**step_ants;
	int					p_ants;
	int					turn;
	int					min_step;
	int					max_step;
	int					c_min_step;
	int					*short_cat;
	int					size_short;
	int					*rooms_cov;
	int					*weight;
	int					*p_weight;
	int					*any_way;
	int					go_next;
	int					prew_steps;
	int					t;
	int					len;
	int					pat;
	int					size_sc;
	int					c_l;
	int					size_r;
	int					arc;
	int					gnl;
	int					gnl_c;
	int					s_ants;
	int					s_rooms;
	int					**a_conn;
	int					ca;
	int					cb;
	int					cc;
	int					cd;
	int					ce;
	int					cf;
	int					fw;
	int					fc;
	int					fv;
	int					fp;
	int					fm;
}						t_lem_in;

void					apt_next_room_for_deksta(t_lem_in *a, int min,
								int kast);
void					apt_dijkstras_algorithm(t_lem_in *a);
void					apt_short_cat(t_lem_in *a, int i, int j);
int						apt_short_cat_1(t_lem_in *a, int i, int j);
void					apt_short_cat_2(t_lem_in *a, int i, int j);

void					apt_finding_the_way(t_lem_in *a, int i);
int						apt_check_repeate(t_lem_in *a, int i, int j);
void					we_have_some_one_problem_plus(t_lem_in *a);
void					we_have_some_one_problem(t_lem_in *a, int kast);
void					apt_next_room_for_deksta_plus(t_lem_in *a, int min);

void					finding_the_way(t_lem_in *a, int i);
int						check_repeate(t_lem_in *a, int i);
void					next_room_for_deksta(t_lem_in *a, int min);
void					dijkstras_algorithm(t_lem_in *a);
void					short_cat(t_lem_in *a);

void					found_more_ways_1(t_lem_in *a);
int						found_more_ways_2(t_lem_in *a, int j);
void					found_more_ways_3(t_lem_in *a, int k, int j);
void					found_more_ways_4(t_lem_in *a, int k, int j);
void					found_more_ways(t_lem_in *a, int j, int k);

int						*combine_ways1(t_lem_in *a, int i, int j);
int						combine_ways2(t_lem_in *a);
void					combine_ways(t_lem_in *a, int i, int j);
void					include_way(t_lem_in *a, int i, int j, int k);
void					include_way_m(t_lem_in *a);

void					relevants(t_lem_in *a, int len, int i);
void					forecast(t_lem_in *a, int len, int i);
int						relevants_len(t_lem_in *a, int i);
void					step_by_step(t_lem_in *a, int stop, int i, int j);

void					initilisation_step_array(t_lem_in *a, int len, int i);
void					step_ants(t_lem_in *a, int len, int i, int j);
void					vis_or_dont_vis(t_lem_in *a, int i, int j);
void					step_solo_way_ants(t_lem_in *a, int i);

void					lem_exit(int i, t_lem_in *a);
void					*music_power(void *lol);
void					check_flags(char **av, t_lem_in *a, int i, int j);
void					functions(t_lem_in *a);

void					add_cells(t_lem_in *a, int fd, int i);
void					add_cells_1(t_lem_in *a);
void					add_cells_2(t_lem_in *a);
void					add_cells_3(t_lem_in *a, int i);

void					put_matrix(t_lem_in *a, int i);
void					put_connect(t_lem_in *a, int left, int right);

void					put_start(t_lem_in *a, int ord);
void					put_rooms(t_lem_in *a, int ord);
void					put_end(t_lem_in *a, int ord);
void					add_rooms_arr(t_lem_in *a);
void					add_matrix_connect(t_lem_in *a, int i, int j);

int						sort_array(t_lem_in *a, int i, int tmp, int len);
int						null_ants_arr(t_lem_in *a, int len, int i, int j);
void					sort_array_way(t_lem_in *a, int i);

int						li_atoi(char *str, unsigned long int ret,
								t_lem_in *a, int j);
int						check_valid_connect(t_lem_in *a, int i, int trigger);
int						support_cvc_f(t_lem_in *a, int j);
int						support_cvc_s(t_lem_in *a, int j);

void					val_ants(t_lem_in *a);
void					valid_rooms_name(t_lem_in *a, int i, int j);
void					count_rooms(t_lem_in *a, int i);
void					initialization_start_and_end(t_lem_in *a,
								int i, int flag);

void					check_room(t_lem_in *a, int len, int i, int pos);
void					check_room_1(t_lem_in *a, int pos);
void					check_way(t_lem_in *a, int len, int i, int pos);
void					check_way_1(t_lem_in *a, int pos);

void					check_valid(t_lem_in *a, int len, int i);
void					check_invalid_str(t_lem_in *a, int ch_pos,
								int start, int end);
int						check_invalid_str_s(int start, t_lem_in *a);
int						check_invalid_str_e(int end, t_lem_in *a);

void					visualisation_1_1(t_lem_in *a);
void					visualisation_1(t_lem_in *a);
void					visualisation(t_lem_in *a);

void					calc_rooms(t_lem_in *a, int i, int j);
void					brez_line(t_lem_in *a);
void					put_ways(t_lem_in *a);
void					start_room(t_lem_in *a, int i, int j, int k);
void					end_room(t_lem_in *a, int i, int j, int k);

void					middle_room(t_lem_in *a, int i, int j, int k);
void					put_rooms_v(t_lem_in *a);
void					get_ants_image(t_lem_in *a, int i, int j);
int						say_good_buy(t_lem_in *a);
int						key_press(int key, t_lem_in *a);

void					go_do_this_3(t_lem_in *a, int i, int j);
void					go_do_this_4_2(t_lem_in *a);
int						go_do_this_4(t_lem_in *a);
void					go_do_this_5(t_lem_in *a);
void					go_do_this_2_2(t_lem_in *a);

void					go_do_this_2_1(t_lem_in *a);
void					go_do_this_2(t_lem_in *a, int i, int j);
int						go_do_this(t_lem_in *a);
void					go_move_this(t_lem_in *a);
void					visualisation_2(t_lem_in *a);

#endif
