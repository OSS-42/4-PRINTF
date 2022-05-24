#VARIABLES

NAME = libftprintf.a
LIBFT = libft.a
LDIR = libft/
TDIR = tests/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
CFLAGSTEST = -o
RM = rm -f
AR = ar rcs

#COLORS
LRED = \033[91m
LGREEN = \033[92m
LYELLOW = \033[93
LMAGENTA = \033[95m
LCYAN = \033[96m
DEF_COLOR = \033[0;39m

#SOURCES

SRC = ft_printf.c ft_printf_utils.c ft_printf_ptr.c

OBJ = $(SRC:.c=.o)

$(V).SILENT:

all:	$(LDIR)/$(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC)
	cp $(LDIR)$(LIBFT) $(NAME)
	@echo "$(LGREEN)...and copied !$(DEF_COLOR)"
	$(AR) $(NAME) $(OBJ)
	@echo "$(LGREEN)Compilation complete !$(DEF_COLOR)"

$(LDIR)/$(LIBFT):
	make -C $(LDIR)
	@echo "$(LGREEN)LIBFT done... !$(DEF_COLOR)"

test1: $(LDIR)/$(LIBFT)
	clear
	$(CC) $(CFLAGSTEST) test $(SRC) $(TDIR)main.c $(LDIR)$(LIBFT)
	@echo "$(LMAGENTA)Voici le résultat des tests (Tests Perso)$(DEF_COLOR)"
	./test
	$(RM) $(TDIR)test

test2: $(LDIR)/$(LIBFT)
	clear
	$(CC) $(CFLAGSTEST) test $(SRC) $(TDIR)test_printf.c $(LDIR)$(LIBFT)
	@echo "$(LMAGENTA)Voici le résultat des tests (Merci Cole !)$(DEF_COLOR)"
	./test
	$(RM) $(TDIR)test

bonus: all

clean:
	$(RM) $(OBJ)
	$(RM) $(LDIR)*.o
	@echo "$(LCYAN)Objects files cleaned !$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)
	$(RM) test
	$(RM) *.o
	@echo "$(LCYAN)Executables files cleaned !$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re