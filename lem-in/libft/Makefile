# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 23:29:50 by ldonnor-          #+#    #+#              #
#    Updated: 2019/07/21 14:01:00 by ldonnor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGECT		= libft
NAME		= $(PROGECT).a
CFLAGS		= -Wall -Werror -Wextra
S_DIR		= src_lib/
S_PIR		= src_prf/
OBJDIR		= obj/
OBJLIR		= $(addprefix $(OBJDIR),$(S_DIR))
OBJPIR		= $(addprefix $(OBJDIR),$(S_PIR))
SRCDIR		= src/
INCDIR		= includes/
CC			= gcc

OBJSRC		= $(OBJLIR)\
			$(OBJPIR)

SRCS		= $(S_DIR)ft_atoi.c\
			$(S_DIR)ft_memccpy.c\
			$(S_DIR)ft_putstr.c\
			$(S_DIR)ft_strmap.c\
			$(S_DIR)ft_memchr.c\
			$(S_DIR)ft_putstr_fd.c\
			$(S_DIR)ft_strmapi.c\
			$(S_DIR)ft_bzero.c\
			$(S_DIR)ft_memcmp.c\
			$(S_DIR)ft_sizenumber.c\
			$(S_DIR)ft_strncat.c\
			$(S_DIR)ft_isalnum.c\
			$(S_DIR)ft_memcpy.c\
			$(S_DIR)ft_strcat.c\
			$(S_DIR)ft_strncmp.c\
			$(S_DIR)ft_isalpha.c\
			$(S_DIR)ft_memdel.c\
			$(S_DIR)ft_strchr.c\
			$(S_DIR)ft_strncpy.c\
			$(S_DIR)ft_isascii.c\
			$(S_DIR)ft_memmove.c\
			$(S_DIR)ft_strclr.c\
			$(S_DIR)ft_strnequ.c\
			$(S_DIR)ft_isdigit.c\
			$(S_DIR)ft_memset.c\
			$(S_DIR)ft_strcmp.c\
			$(S_DIR)ft_strnew.c\
			$(S_DIR)ft_isprint.c\
			$(S_DIR)ft_negative_l.c\
			$(S_DIR)ft_strcpy.c\
			$(S_DIR)ft_strnstr.c\
			$(S_DIR)ft_itoa.c\
			$(S_DIR)ft_strdel.c\
			$(S_DIR)ft_strrchr.c\
			$(S_DIR)ft_lstadd.c\
			$(S_DIR)ft_strdup.c\
			$(S_DIR)ft_strsplit.c\
			$(S_DIR)ft_lstdel.c\
			$(S_DIR)ft_putchar.c\
			$(S_DIR)ft_strequ.c\
			$(S_DIR)ft_strstr.c\
			$(S_DIR)ft_lstdelone.c\
			$(S_DIR)ft_putchar_fd.c\
			$(S_DIR)ft_striter.c\
			$(S_DIR)ft_strsub.c\
			$(S_DIR)ft_lstiter.c\
			$(S_DIR)ft_putendl.c\
			$(S_DIR)ft_striteri.c\
			$(S_DIR)ft_strtrim.c\
			$(S_DIR)ft_lstmap.c\
			$(S_DIR)ft_putendl_fd.c\
			$(S_DIR)ft_strjoin.c\
			$(S_DIR)ft_tolower.c\
			$(S_DIR)ft_lstnew.c\
			$(S_DIR)ft_putnbr.c\
			$(S_DIR)ft_strlcat.c\
			$(S_DIR)ft_toupper.c\
			$(S_DIR)ft_memalloc.c\
			$(S_DIR)ft_putnbr_fd.c\
			$(S_DIR)ft_strlen.c\
			$(S_DIR)ft_lstdeldel.c\
			$(S_DIR)get_next_line.c\
			$(S_DIR)ft_revers.c\
			$(S_PIR)array_of_param_pf.c\
			$(S_PIR)check_valid_pf.c\
			$(S_PIR)feed_x_pf.c\
			$(S_PIR)float_step1_pf.c\
			$(S_PIR)float_step6_pf.c\
			$(S_PIR)ft_printf.c\
			$(S_PIR)hex_check_fl_pf.c\
			$(S_PIR)how_mach_par_pf.c\
			$(S_PIR)itoa_sig_dec_pf.c\
			$(S_PIR)left_al_var_pf.c\
			$(S_PIR)num_zero_pf.c\
			$(S_PIR)oct_num_zero_pf.c\
			$(S_PIR)other_oct_pf.c\
			$(S_PIR)put_space_pf.c\
			$(S_PIR)ret_float_pf.c\
			$(S_PIR)ret_int_pf.c\
			$(S_PIR)zero_val_pf.c

HEADERS		= $(INCDIR)libft.h\
			$(INCDIR)ft_printf.h

GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CHANGE = $(BLUE)
TAB = "\	\	"
FTAB = "\	\	\	"

OBJ			= $(SRCS:.c=.o)

all: $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c $(HEADERS)
	@find . -type f -name "obj" -delete
	@mkdir -p obj/
	@find ./obj -type f -name "src_lib" -delete
	@find ./obj -type f -name "src_prf" -delete
	@mkdir -p $(OBJLIR) $(OBJPIR)
	@echo "$(CHANGE)∰$(RESET)\c"
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(addprefix $(OBJDIR),$(OBJ))
	@echo "\n\n$(NAME):$(TAB)$(YELLOW)object files$(TAB)$(GREEN)were created.$(RESET)"
	@ar rcs $(NAME) $^
	@echo "$(NAME):$(TAB)$(YELLOW)$(NAME)$(FTAB)$(GREEN)was  created.$(RESET)\n"

tony: clean re

clean:
	@rm -f $(OBJ)
	@echo "$(NAME):$(TAB)$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)"
	@find . -type f -name "obj" -delete
	@mkdir -p obj
	@rm -Rf obj
	@echo "$(NAME):$(TAB)$(YELLOW)object folders$(TAB)$(RED)were deleted.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME):$(TAB)$(YELLOW)$(NAME)$(FTAB)$(RED)was  deleted.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
