# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldonnor- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 23:29:50 by ldonnor-          #+#    #+#              #
#    Updated: 2019/01/10 00:57:18 by ldonnor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra
S_DIR		= src/
$(CC)		= gcc

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

OBJ			= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

tony: re
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
