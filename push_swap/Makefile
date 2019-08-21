# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrewkirpiy <andrewkirpiy@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 22:31:23 by ldonnor-          #+#    #+#              #
#    Updated: 2019/07/20 00:56:46 by andrewkirpi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap

NAME2	= checker

SRC1		= ft_push_swap.c\
			tracing.c\
			pointer_on_null.c\
			validation.c\
			add_cells.c\
			comparison.c\
			operation_s.c\
			operation_r.c\
			operation_rr.c\
			operation_p.c\
			order.c\
			sort.c\
			universal.c\
			check_answer_p6.c\
			check_answer.c\
			hard_check4.c\
			mini_sort.c\


SRC2		= checker.c\
			tracing.c\
			pointer_on_null.c\
			validation.c\
			add_cells.c\
			comparison.c\
			operation_s.c\
			operation_r.c\
			operation_rr.c\
			operation_p.c\
			order.c\
			sort.c\
			universal.c\
			check_answer_p6.c\
			check_answer.c\
			hard_check4.c\
			mini_sort.c\
			go_check.c\
			by.c\

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

OBJ1	= $(addprefix $(OBJDIR),$(SRC1:.c=.o))

OBJ2	= $(addprefix $(OBJDIR),$(SRC2:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -O3

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

all: $(FT_LIB) $(MLX_LIB) $(NAME1) $(NAME2)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@find . -type f -name "obj" -delete
	@mkdir -p obj/
	@echo "$(CHANGE)∰$(RESET)\c"
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME1): $(OBJ1)
	@echo "\n$(NAME1):$(TAB)$(YELLOW)object files$(TAB)$(GREEN)were created.$(RESET)"
	@$(CC) -framework OpenCL $(OBJ1) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME1)
	@echo "$(NAME1):$(TAB)$(YELLOW)$(NAME1)$(TAB)$(GREEN)was  created.$(RESET)\n"

$(NAME2): $(OBJ2)
	@echo "\n$(NAME2):$(TAB)$(YELLOW)object files$(TAB)$(GREEN)were created.$(RESET)"
	@$(CC) -framework OpenCL $(OBJ2) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME2)
	@echo "$(NAME1):$(TAB)$(YELLOW)$(NAME2)$(FTAB)$(GREEN)was  created.$(RESET)"

andrew:
	@rm -rf $(NAME1)
	@echo "\n$(NAME1):$(TAB)$(YELLOW)$(NAME1)$(TAB)$(RED)was  deleted.$(RESET)"
	@rm -rf $(NAME2)
	@echo "$(NAME1):$(TAB)$(YELLOW)$(NAME2)$(FTAB)$(RED)was  deleted.$(RESET)"
	@rm -rf $(OBJDIR)
	@find . -type f -name "obj" -delete
	@mkdir -p obj
	@rm -Rf obj
	@echo "$(NAME1):$(TAB)$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)\n"
	@make

clean:
	@rm -rf $(OBJDIR)
	@find . -type f -name "obj" -delete
	@mkdir -p obj
	@rm -Rf obj
	@echo "$(NAME1):$(TAB)$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)\n"
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME1)
	@echo "\n$(NAME1):$(TAB)$(YELLOW)$(NAME1)$(TAB)$(RED)was  deleted.$(RESET)"
	@rm -rf $(NAME2)
	@echo "$(NAME1):$(TAB)$(YELLOW)$(NAME2)$(FTAB)$(RED)was  deleted.$(RESET)\n"
	@make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re
