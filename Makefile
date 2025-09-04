NAME = pipex.a
CFLAGS = -Wall -Wextra -Werror
SOURCE =    ./libft/ft_atoi.c       \
			./libft/ft_bzero.c      \
			./libft/ft_calloc.c     \
			./libft/ft_isalnum.c    \
			./libft/ft_isalpha.c    \
			./libft/ft_isascii.c    \
			./libft/ft_isdigit.c    \
			./libft/ft_isprint.c    \
			./libft/ft_itoa.c       \
			./libft/ft_memchr.c     \
			./libft/ft_memcmp.c     \
			./libft/ft_memcpy.c     \
			./libft/ft_memmove.c    \
			./libft/ft_memset.c     \
			./libft/ft_putchar_fd.c \
			./libft/ft_putendl_fd.c \
			./libft/ft_putnbr_fd.c  \
			./libft/ft_putstr_fd.c  \
			./libft/ft_split.c      \
			./libft/ft_strchr.c     \
			./libft/ft_strdup.c     \
			./libft/ft_striteri.c   \
			./libft/ft_strjoin.c    \
			./libft/ft_strlcat.c    \
			./libft/ft_strlcpy.c    \
			./libft/ft_strlen.c     \
			./libft/ft_strmapi.c    \
			./libft/ft_strncmp.c    \
			./libft/ft_strnstr.c    \
			./libft/ft_strrchr.c    \
			./libft/ft_strtrim.c    \
			./libft/ft_substr.c     \
			./libft/ft_tolower.c    \
			./libft/ft_toupper.c	\
			parser.c				\
			pipes.c

OBJECTS =./libft/ft_atoi.o       \
			./libft/ft_bzero.o      \
			./libft/ft_calloc.o     \
			./libft/ft_isalnum.o    \
			./libft/ft_isalpha.o    \
			./libft/ft_isascii.o    \
			./libft/ft_isdigit.o    \
			./libft/ft_isprint.o    \
			./libft/ft_itoa.o       \
			./libft/ft_memchr.o     \
			./libft/ft_memcmp.o     \
			./libft/ft_memcpy.o     \
			./libft/ft_memmove.o    \
			./libft/ft_memset.o     \
			./libft/ft_putchar_fd.o \
			./libft/ft_putendl_fd.o \
			./libft/ft_putnbr_fd.o  \
			./libft/ft_putstr_fd.o  \
			./libft/ft_split.o      \
			./libft/ft_strchr.o     \
			./libft/ft_strdup.o     \
			./libft/ft_striteri.o   \
			./libft/ft_strjoin.o    \
			./libft/ft_strlcat.o    \
			./libft/ft_strlcpy.o    \
			./libft/ft_strlen.o     \
			./libft/ft_strmapi.o    \
			./libft/ft_strncmp.o    \
			./libft/ft_strnstr.o    \
			./libft/ft_strrchr.o    \
			./libft/ft_strtrim.o    \
			./libft/ft_substr.o     \
			./libft/ft_tolower.o    \
			./libft/ft_toupper.o	\
			parser.o				\
			pipes.o


all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs -o $(NAME) $(OBJECTS)
	cc $(CFLAGS) pipex.c $(NAME) -o pipex
clean:
	@rm -rf $(OBJECTS)
fclean: $(OBJECTS)
	@rm -rf $(OBJECTS) $(NAME) pipex
re: fclean all
.PHONY: all clean fclean re bonus
bonus:
	
comp:
	@cc $(CFLAGS) -g3 pipex.c pipex.a
run: comp
	@./a.out readme.txt cat  "grep exit"  "tr a-z A-Z" deneme.txt