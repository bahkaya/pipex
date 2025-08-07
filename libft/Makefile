# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 16:24:29 by bahkaya           #+#    #+#              #
#    Updated: 2025/06/20 15:10:18 by bahkaya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
P = program

SOURCE =    ft_atoi.c       \
			ft_bzero.c      \
			ft_calloc.c     \
			ft_isalnum.c    \
			ft_isalpha.c    \
			ft_isascii.c    \
			ft_isdigit.c    \
			ft_isprint.c    \
			ft_itoa.c       \
			ft_memchr.c     \
			ft_memcmp.c     \
			ft_memcpy.c     \
			ft_memmove.c    \
			ft_memset.c     \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c  \
			ft_putstr_fd.c  \
			ft_split.c      \
			ft_strchr.c     \
			ft_strdup.c     \
			ft_striteri.c   \
			ft_strjoin.c    \
			ft_strlcat.c    \
			ft_strlcpy.c    \
			ft_strlen.c     \
			ft_strmapi.c    \
			ft_strncmp.c    \
			ft_strnstr.c    \
			ft_strrchr.c    \
			ft_strtrim.c    \
			ft_substr.c     \
			ft_tolower.c    \
			ft_toupper.c

OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)
$(NAME): $(OBJECTS)
	ar rcs -o $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re vscode comp run pclean

vscode: 
	@code .

comp: $(P)
	@$(CC) $(CFLAGS) program.c libft.a 
$(P):
	touch program.c
run:
	@./a.out

pclean: $(P)
	@rm -rf $(P) ./a.out
