NAME = libft.a

LIBCFUN = \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c  ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c  ft_putnbr_fd.c \

LIBCBON = \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c #-I -nostartfiles

RM = rm -f

AR = ar rcs

OBJFUN = $(LIBCFUN:.c=.o)
OBJBON = $(LIBCBON:.c=.o)

all:	$(NAME)

$(NAME): $(OBJFUN)
	@$(CC) $(CFLAGS) $(LIBCFUN)
	@$(AR) $(NAME) $(OBJFUN)

clean:
	@$(RM) $(OBJFUN) $(OBJBON)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

#==================== For Ubuntu in WSL =====================#
#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(LIBCFUN) $(LIBCBON)
#	gcc -nostartfiles -shared -o libft.so $(OBJFUN) $(OBJBON)
#============================================================#

bonus: $(NAME) $(OBJFUN)
	@$(CC) $(CFLAGS) $(LIBCBON)
	@$(AR) $(NAME) $(OBJBON)

.PHONY: all clean fclean re bonus

#=================== DONE BUT NOT ASKED FOR ==================#
# ft_strmap.c ft_strstr.c ft_strcat.c  ft_strcmp.c ft_strcpy.c
# ft_strncat.c  ft_strncpy.c 
# ft_putchar.c ft_putnbr.c ft_putstr.c
#======================== NOT ASK FOR ========================#
# ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c
# ft_striter.c ft_strequ.c ft_strnequ.c ft_putendl.c 
#=============================================================#