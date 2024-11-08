SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)


CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = .

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

NAME = ft_printf.a

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
