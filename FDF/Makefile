# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 22:31:23 by ldonnor-          #+#    #+#              #
#    Updated: 2019/06/01 11:45:34 by ldonnor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= main.c\
			read_map_fdf.c\
			calk_params2_fdf.c\
			check_hex_fdf.c\
			clean_list_fdf.c\
			test_anton_fdf.c\
			give_me_line_fdf.c\
			paint_line_fdf.c\
			paint_map_fdf.c\
			info_window_fdf.c\
			key_press_fdf.c\
			many_b_color_fdf.c\
			more_r_color_fdf.c\
			map_top_fdf.c\
			many_alfa_fdf.c\
			more_gamma_fdf.c\
			see_iso_fdf.c\
			go_go_to_start_fdf.c\
			say_good_buy_fdf.c\
			mouse_press_fdf.c\
			color_preset_fdf.c\
			more_preset5_fdf.c\
			more_preset10_fdf.c\
			ret_stock_fdf.c\
			calk_parametrs_fdf.c\
			map_lt_fdf.c\
			centrolize_fdf.c\
			more_r_col_h_fdf.c\
			color_pres_h_fdf.c\
			more_pres_h5_fdf.c\
			more_pres_h10_fdf.c\
			change_col_pres_fdf.c\
			text_fdf.c


GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CHANGE = \033[0;35m
TAB = "\	\	"
FTAB = "\	\	\	"

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

MLX		= ./miniLibX/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: $(FT_LIB) $(MLX_LIB) $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@find . -type f -name "obj" -delete
	@mkdir -p obj/
	@echo "$(CHANGE)∰$(RESET)\c"
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	@echo "\n\n$(NAME):$(FTAB)$(YELLOW)object files$(TAB)$(GREEN)were created.$(RESET)"
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "$(NAME):$(FTAB)$(YELLOW)$(NAME)$(FTAB)$(GREEN)was  created.$(RESET)"

tony: clean re

tony2:
	@rm -rf $(NAME)
	@echo "\n$(NAME):$(FTAB)$(YELLOW)$(NAME)$(FTAB)$(RED)was  deleted.$(RESET)"
	@rm -rf $(OBJDIR)
	@find . -type f -name "obj" -delete
	@mkdir -p obj
	@rm -Rf obj
	@echo "$(NAME):$(FTAB)$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)\n"
	@make

clean:
	@rm -rf $(OBJDIR)
	@find . -type f -name "obj" -delete
	@mkdir -p obj
	@rm -Rf obj
	@echo "$(NAME):$(FTAB)$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)\n"
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@echo "\n$(NAME):$(FTAB)$(YELLOW)$(NAME)$(FTAB)$(RED)was  deleted.$(RESET)\n"
	@make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re