/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:25:47 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/01/20 16:26:04 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"

int			ft_basic_calculation_fl(int *c, char ***sup, int **a);
int			ft_new_mem_fl(char ***sup, int *c);
int			ft_eazy_fl(char ***s, int *c, int **a);
int			ft_hard_fl(char ***s, int *c, int **a);
int			ft_norm_fl(char ***s, int *c, int **a);

void		ft_bas_calc_extra_lines_fl(int *c, char ***sup, int **a);
int			**ft_new_arr_fl(int **swap, int *c);
int			ft_free_swap_fl(int **swap, int *c, char **line, char ***s);
void		ft_del_mino_fl(char ***s, int *c);

int			ft_conversion_fl(char **line, int *c);
int			ft_del_stars_fl(int *c, char ***s, char **line);
void		ft_fear_fl(int *c, char ***s);
int			ft_basik_conversion_fl(char **line, int *c, char ***s);
int			ft_byby_fl(char **line, int *c, char ***s);

char		**ft_conv_eazy_fl(char **l, int *c);
char		**ft_conv_eazy_p1_fl(char **l, int *c);
char		**ft_conv_eazy_p2_fl(char **l, int *c);
char		**ft_conv_eazy_p3_fl(char **l, int *c);

int			ft_emergency_exit_fl(int fd, char **line, int *counter);
int			ft_compliance_fl(char **line, int *count);
void		ft_compliance_fll(char **l, int *c);
int			ft_read_fl(int fd, char **line, int *coun);
int			ft_read_fll(char *line, int *count);

int			ft_printmap_fl(char ***s, char **line, int *c, int **swap);

#endif
