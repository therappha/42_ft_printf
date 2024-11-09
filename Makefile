SRCS = ft_printf.c ft_putchars.c ft_putnbr.c ft_putptr.c
OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = .

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re:	fclean all
