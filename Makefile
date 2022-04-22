NAME = libftprintf.a

#========== .c pour printf ==========#
... = ft_printf.c 

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c

RM = rm -f

AR = ar rcs

.... = $(...:.c=.o)

LIBCOBJ = xxx.o

#========== archiver ft_ libft.h utilisées ==========#

all:	$(NAME)

$(NAME): $(...)
	$(CC) $(CFLAGS) $(...)
	$(AR) $(NAME) $(....) + #libft srcs

clean:
	$(RM) $(...) $(....)
	cd libft && clean -s

fclean: clean
	$(RM) $(NAME)
	cd libft && fclean -s

re: fclean all

.PHONY: all clean fclean re