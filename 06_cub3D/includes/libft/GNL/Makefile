NAME = gnl.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS	= \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar r $@ $(OBJS)

$(OBJS):%.o : %.c
	$(CC) $(CFLAG) -c -o $@ $*.c

re : fclean all

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

.PHONY: all bonus clean fclean re
