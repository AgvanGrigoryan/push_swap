CFLAGS = -Wall -Wextra -Werror 
CC = cc $(CFLAGS)

NAME = push_swap

HDRS = push_swap.h
SRCS = print_funcs.c push_swap.c input_validation.c swap.c push.c rotate.c reverse_rotate.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) 	
	$(CC) $(OBJS) -o $(NAME)
	
%.o: %.c $(HDRS) Makefile
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
