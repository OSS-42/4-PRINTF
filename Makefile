#VARIABLES

NAME = libprintf.a
LIBFT = libft.a
LDIR = libft/
TDIR = tests/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
CFLAGSTEST = -o
RM = rm -f
AR = ar rcs

#COLORS
LRED = \e[91m
LGREEN = \e[92m
LYELLOW = \e[93
LMAGENTA = \e[95m
LCYAN = \e[96m
DEF_COLOR = \033[0;39m

#SOURCES

SRC = ft_printf.c ft_printf_utils.c ft_printf_ptr.c

OBJ = $(SRC:.c=.o)

$(V).SILENT:

all:	$(LDIR)/$(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LDIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(SRC)
	$(AR) $(NAME) $(OBJ)
	@echo "$(LGREEN)Compilation terminée !$(DEF_COLOR)"

$(LDIR)/$(LIBFT):
	make -sC $(LDIR)
	@echo "$(LGREEN)LIBFT réalisée !$(DEF_COLOR)"

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
	@echo "$(LCYAN)Fichiers objets supprimés !$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)
	$(RM) *.o
	@echo "$(LCYAN)Fichiers exécutables supprimés !$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re