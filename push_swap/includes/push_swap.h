/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:12:57 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/07/21 12:16:06 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "mlx.h"
# include "libft.h"

# define SA				universal(sa, "sa\n", ds)
# define SB				universal(sb, "sb\n", ds)
# define SS				universal(ss, "ss\n", ds)
# define PA				universal(pa, "pa\n", ds)
# define PB				universal(pb, "pb\n", ds)
# define RA				universal(ra, "ra\n", ds)
# define RB				universal(rb, "rb\n", ds)
# define RR				universal(rr, "rr\n", ds)
# define RRA			universal(rra, "rra\n", ds)
# define RRB			universal(rrb, "rrb\n", ds)
# define RRR			universal(rrr, "rrr\n", ds)

# define RUN_NEXT		ds->run = ds->run->next
# define RUN_PREV		ds->run = ds->run->prev

# define RUN_NEXT_B		ds->temp = ds->temp->next
# define RUN_PREV_B		ds->temp = ds->temp->prev

# define FIRST			ds->a_beg->ord
# define SECOND			ds->a_beg->next->ord
# define THIRD			ds->a_beg->next->next->ord

# define FIRST_B		ds->b_beg->ord
# define SECOND_B		ds->b_beg->next->ord
# define THIRD_B		ds->b_beg->next->next->ord

typedef struct			s_cell
{
	int					val;
	int					ord;
	char				flag;
	struct s_cell		*next;
	struct s_cell		*prev;
}						t_cell;

typedef struct			s_push
{
	t_cell				*a_beg;
	t_cell				*b_beg;
	t_cell				*temp;
	t_cell				*run;
	char				*temp_str;
	char				*str;
	char				*gnl_str;
	int					*extra_stack;
	int					balance;
	int					next;
	int					last;
	int					stop;
	int					temp_num;
	int					size_a;
	int					size_b;
	int					size_e;
	int					min;
	int					mid;
	int					vis;
	int					next_mid;
	int					max;
	int					i;
	int					j;
	int					fl_ch;
	int					fl;
	int					ca;
	int					cb;
	int					cd;
	int					ce;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img_adr;
	int					pix;
	int					bpp;
	int					stride;
	int					endian;
	int					s_x;
	int					s_y;
	int					gnl;
	int					this_swap;
}						t_push;

void					pre_check_valid(t_push *ds);
void					bubbles(t_push *ds);
void					pointer_on_null(t_push *ds);
void					tracing(t_push *ds, char *src);
void					chek_valid(t_push *ds);
void					check_equally(t_push *ds);
int						check_finish(t_push *ds);
int						ps_atoi(t_push *ds, unsigned int i, int j);
void					add_cells(t_push *ds);
void					add_begin_cell(t_push *ds);
void					bubbles(t_push *ds);
void					add_extra_stack(t_push *ds);
void					sa(t_push *ds);
void					sb(t_push *ds);
void					ss(t_push *ds);
void					ra(t_push *ds);
void					rb(t_push *ds);
void					rr(t_push *ds);
void					rra(t_push *ds);
void					rrb(t_push *ds);
void					rrr(t_push *ds);
void					pa(t_push *ds);
void					pa_p(t_push *ds);
void					pb(t_push *ds);
void					pb_p(t_push *ds);
void					put_order(t_push *ds);
void					w_mid(t_push *ds);
void					short_cut(t_push *ds);
void					sort_a(t_push *ds);
void					search_max(t_push *ds);
void					begin_sort(t_push *ds);
void					sort_stack_b(t_push *ds);
void					sort_stack_a(t_push *ds);
void					sort_second(t_push *ds);
void					in_sort_stack_b(t_push *ds);
void					universal(void	(*un_comm) (t_push *),
									char *str, t_push *ds);
void					hard_check5(t_push *a, int i);
void					hard_check6(t_push *a, int i);
void					hard_check_answer(t_push *a);
void					check_answer_p6(t_push *a);
void					check_answer_p5(t_push *a);
void					check_answer_p4(t_push *a);
void					check_answer_p3(t_push *a);
void					check_answer_p2(t_push *a);
void					check_answer(t_push *a);
void					hard_check1(t_push *a, int i);
void					hard_check2(t_push *a, int i);
void					hard_check3(t_push *a, int i);
void					hard_check4(t_push *a, int i);
void					duo_sort(t_push *ds);
void					trio_sort(t_push *ds);
void					mini_sort(t_push *ds);
void					quadro_sort(t_push *ds);
void					penta_sort(t_push *ds);
void					initialize(t_push *ds);
void					window_size(t_push *ds);
void					visualization(t_push *ds);
int						by_by(t_push *ds);
int						key_press(int key, t_push *ds);
void					get_image(t_push *ds, int i, int j);
void					print_stack(t_push *ds);
void					go_check_2(t_push *ds);
void					go_check_1(t_push *ds);
int						go_check(t_push *ds);
void					by(t_push *ds);
void					null_cell(t_push *ds);
void					push_go(t_push *ds, int argc, char **argv);

#endif
