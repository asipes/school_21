# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asipes <asipes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 17:37:20 by ldonnor-          #+#    #+#              #
#    Updated: 2019/04/29 21:14:06 by asipes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CFLAGS		+= -Wall -Werror -Wextra
CFLAGS		+= -I libft/includes/
S_DIR		= src/
CC			= gcc


SRCS		= $(S_DIR)check_valid_pf.c\
			$(S_DIR)flag_zero.c\
			$(S_DIR)ft_other_opt.c\
			$(S_DIR)ft_printf.c\
			$(S_DIR)give_me_param_pf.c\
			$(S_DIR)hard_check_pf.c\
			$(S_DIR)hex_put_num.c\
			$(S_DIR)initialize_pf.c\
			$(S_DIR)itoa_float_p2.c\
			$(S_DIR)itoa_float.c\
			$(S_DIR)itoa_hex.c\
			$(S_DIR)itoa_oct.c\
			$(S_DIR)itoa_sig_dec.c\
			$(S_DIR)itoa_uns_dec.c\
			$(S_DIR)left_al.c\
			$(S_DIR)num_zero.c\
			$(S_DIR)numlen_sig_pf.c\
			$(S_DIR)oct_put_num.c\
			$(S_DIR)put_itoa_float.c\
			$(S_DIR)read_type_and_spec_pf.c\
			$(S_DIR)ret_char_pf.c\
			$(S_DIR)ret_float_pf.c\
			$(S_DIR)ret_int_pf.c\
			$(S_DIR)ret_string_pf.c\
			$(S_DIR)zero_val.c




LIBFT		= libft/libft.a

OBJ			= $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	make -C libft
	ar rc $(NAME) $(OBJ) ./libft/src/*.o

tony: re
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
