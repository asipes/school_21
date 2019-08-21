# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 23:29:50 by ldonnor-          #+#    #+#              #
#    Updated: 2019/01/15 15:36:25 by ldonnor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit
CFLAGS		+= -Wall -Werror -Wextra
CFLAGS		+= -I libft/includes/
S_DIR		= src/
$(CC)		= gcc

SRCS		= src/main.c \
			src/ft_conv_eazy_fl.c \
			src/ft_printmap_fl.c \
			src/ft_basic_calculation_fl.c \
			src/ft_emergency_exit_fl.c\
			src/ft_conversion_fl.c\
			src/ft_bas_calc_extra_lines_fl.c

LIBFT		= libft/libft.a

OBJ			= $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

tony: re
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
