/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:16:23 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/21 14:08:07 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct				s_tab
{
	int						*obel_x;
	char					*temp;
	char					*form;
	char					*fl;
	char					*ty;
	char					*tf;
	char					*po;
	int						count_a;
	int						count_b;
	int						count_c;
	long long int			p_int;
	double					p_float;
	long double				p_double;
	char					p_char;
	char					*p_string;
	unsigned long long int	p_point;
	size_t					abs_len;
	va_list					ap;
	int						error;
	int						parametr;
	int						parametr_i;
	int						parametr_f;
	int						parametr_d;
	int						int_temp;
	int						len;
	int						space;
	int						zero;
	int						sig;
	char					*mass;
	char					*arr;
	long double				tmp_a;
	long double				tmp_b;
	unsigned long long int	first;
	char					sym;
	int						count_m;
	int						stop;
	int						len_num;
	int						full;
	long long int			int_max;
}							t_tab;

int							ft_printf(char *format, ...);
t_tab						*exit_pf(t_tab *a);

t_tab						*no_valid_pf(t_tab *a);
t_tab						*array_of_param_pf(t_tab *a);
t_tab						*check_valid_pf(t_tab *a);

void						flag_zero_pf(t_tab *a, unsigned long long int num);

void						ft_other_opt_p_pf(t_tab *a, long long int num);
void						ft_other_opt_pf(t_tab *a, long long int num);

t_tab						*junction_p2_pf(va_list cap, t_tab *a);
t_tab						*junction_pf(va_list cap, t_tab *a);
t_tab						*fing_my_param_pf(t_tab *a, va_list cap);
t_tab						*give_me_param_pf(t_tab *a);

t_tab						*hard_check_p3_pf(t_tab *a);

t_tab						*hard_check_p2_pf(t_tab *a);
t_tab						*hard_check_p1_pf(t_tab *a);
t_tab						*read_star_pf(t_tab *a);
t_tab						*duck_star_pf(t_tab *a);
t_tab						*hard_check_pf(t_tab *a);

void						hex_put_num_pf(t_tab *a,
								unsigned long long int num);

t_tab						*memory_error_pf(t_tab *a);
t_tab						*clean_my_array_pf(t_tab *a);
t_tab						*feed_x_pf(t_tab *a);
t_tab						*how_mach_par_pf(t_tab *a);
t_tab						*initialize_pf(t_tab *a);

void						float_step6_pf(t_tab *a);
void						float_step5_pf(t_tab *a, long double num);

void						float_step4_pf(t_tab *a);
void						float_step3_pf(t_tab *a, long double num);
void						float_step2_pf(t_tab *a);
void						float_step1_pf(t_tab *a, long double num);
void						itoa_float_pf(t_tab *a, long double num);

void						hex_null_pf(t_tab *a);
void						hex_num_zero_pf(t_tab *a, unsigned long long num);
void						hex_left_al_pf(t_tab *a,
								unsigned long long int num);
void						other_hex_pf(t_tab *a, unsigned long long int num);
t_tab						*itoa_hex_pf(t_tab *a, unsigned long long int num);

void						oct_left_al_pf(t_tab *a,
								unsigned long long int num);
void						oct_num_zero_pf(t_tab *a,
								unsigned long long int num);
void						oct_null_pf(t_tab *a);
void						other_oct_pf(t_tab *a, unsigned long long int num);
t_tab						*itoa_oct_pf(t_tab *a, unsigned long long int num);

void						put_num_pf(t_tab *a, unsigned long long int num);
void						put_zero_pf(t_tab *a);
void						put_space_pf(t_tab *a);
void						other_put_pf(t_tab *a, unsigned long long int num);
t_tab						*itoa_sig_dec_pf(t_tab *a, long long int num);

t_tab						*itoa_uns_dec_pf(t_tab *a,
								unsigned long long int num);

void						left_al_var_pf(t_tab *a);
void						left_al_pf(t_tab *a, unsigned long long int num);

void						num_zero_null_pf(t_tab *a);
void						num_zero_left_pf(t_tab *a);
void						num_zero_pf(t_tab *a);

int							numlen_sig_pf(unsigned long long int num,
								size_t base);

void						oct_put_num_pf(t_tab *a,
								unsigned long long int num);

void						float_num_zero_pf(t_tab *a);
void						float_left_al_pf(t_tab *a);
void						other_float_pf(t_tab *a);
t_tab						*put_itoa_float_pf(t_tab *a);

t_tab						*read_ts_p4_pf(t_tab *a);
t_tab						*read_ts_p3_pf(t_tab *a);
t_tab						*read_ts_p2_pf(t_tab *a);
t_tab						*read_type_and_spec_pf(t_tab *a);

void						zero_char_pf(t_tab *a, char c);
void						char_left_al_pf(t_tab *a, char c);
void						other_char_pf(t_tab *a, char c);
t_tab						*ret_char_pf(t_tab *a, char c);

void						check_inf_pf(t_tab *a, double num);
int							check_nan_pf(t_tab *a, double num);
t_tab						*ret_float_pf(t_tab *a, long double num);

long long int				non_uns_int_pf(t_tab *a, long long int i);
unsigned long long int		this_uns_int_pf(t_tab *a, unsigned long long int i);
t_tab						*ret_int_pf(t_tab *a, long long int i);

void						put_str_pf(t_tab *a, char *string);
t_tab						*ret_string_pf(t_tab *a, char *string);

void						hex_chec_len_pf(t_tab *a);
void						hex_check_fl_pf(t_tab *a);
void						check_sig_pf(t_tab *a, long long int num);
void						zero_val_pf(t_tab *a);

t_tab						*percent_type_pf(t_tab *a);

t_tab						*ret_point_pf(t_tab *a);

void						faster_faster_pf(t_tab *a);

#endif
