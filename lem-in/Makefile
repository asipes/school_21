# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 22:31:23 by ldonnor-          #+#    #+#              #
#    Updated: 2019/08/08 16:19:05 by ldonnor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGECT = lem-in
NAME1	= $(PROGECT)
#NAME2	= checker

SRC1		= main.c\
			apdate_deikstra_1.c\
			apdate_deikstra.c\
			finding_the_way.c\
			found_more_ways_1.c\
			found_more_ways.c\
			links_2_3_4.c\
			links.c\
			parser.c\
			put_value_1.c\
			put_value.c\
			sort.c\
			validation_1.c\
			validation_2.c\
			validation_3.c\
			validation.c\
			visualisation.c\
			visualisation1.c\
			visualisation2.c\
			visualisation3.c\
			visualisation4.c\



SRC2		= mainch.c\

HEADERS 	= $(INCDIR)lem_in.h

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

$(OBJDIR)%.o:$(SRCDIR)%.c $(HEADERS)
	@find . -type f -name "obj" -delete
	@mkdir -p obj/
	@echo "$(CHANGE)∰$(RESET)\c"
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME1): $(OBJ1)
	@echo "\n$(NAME1):$(FTAB)$(YELLOW)object files$(TAB)$(GREEN)were created.$(RESET)"
	@$(CC) -framework OpenCL $(OBJ1) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME1)
	@echo "$(NAME1):$(FTAB)$(YELLOW)$(NAME1)$(FTAB)$(GREEN)was  created.$(RESET)\n"

$(NAME2): $(OBJ2)
	@echo "\n$(NAME2):$(TAB)$(YELLOW)object files$(TAB)$(GREEN)were created.$(RESET)"
	@$(CC) -framework OpenCL $(OBJ2) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME2)
	@echo "$(NAME1):$(TAB)$(YELLOW)$(NAME2)$(FTAB)$(GREEN)was  created.$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@find . -type f -name "obj" -delete
	@mkdir -p obj
	@rm -Rf obj
	@echo "$(NAME1):$(FTAB)$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)\n"
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME1)
	@echo "\n$(NAME1):$(FTAB)$(YELLOW)$(NAME1)$(FTAB)$(RED)was  deleted.$(RESET)"
	@rm -rf $(NAME2)
	@echo "$(NAME1):$(FTAB)$(YELLOW)$(NAME2)$(FTAB)$(RED)was  deleted.$(RESET)\n"
	@make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re
