NAME = libftprintf.a
LIBFT = libft.a
LDIR = libft/

SRC = ft_printf.c ft_printf_utils.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c
CFLAGSTEST = -Wall -Werror -Wextra -o

RM = rm -f

AR = ar rcs

OBJ = $(SRC:.c=.o)

all:	$(LDIR)/$(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LDIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(SRC)
	$(AR) $(NAME) $(OBJ)

$(LDIR)/$(LIBFT):
	$(MAKE) -C $(LDIR)

test1: $(LDIR)/$(LIBFT)
	clear
	$(CC) $(CFLAGSTEST) test $(SRC) main.c $(LDIR)$(LIBFT)
	./test
	$(RM) test

test2: $(LDIR)/$(LIBFT)
	clear
	$(CC) $(CFLAGSTEST) test $(SRC) test_printf.c $(LDIR)$(LIBFT)
	./test
	$(RM) test

clean:
	$(RM) $(OBJ)
	$(RM) $(LDIR)*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)
	$(RM) *.o

re: fclean all

.PHONY: all clean fclean re