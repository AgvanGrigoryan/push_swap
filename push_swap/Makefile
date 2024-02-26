CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CC = cc $(CFLAGS)

NAME = push_swap
BONUS_NAME = checker

HDRS = push_swap.h
SRCS = push_swap.c input_validation.c push_swap_sort.c \
		swap.c push.c rotate.c reverse_rotate.c\
		push_swap_utils.c push_swap_utils2.c push_swap_utils3.c\
		math_utils.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = checker.c input_validation.c push_swap_sort.c get_next_line.c\
	swap.c push.c rotate.c reverse_rotate.c\
	push_swap_utils.c push_swap_utils2.c push_swap_utils3.c\
	math_utils.c get_next_line_utils.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -o $(BONUS_NAME)

$(NAME): $(OBJS) 	
	$(CC) $(OBJS) -o $(NAME)
	
%.o: %.c $(HDRS) Makefile
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)
fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
re: fclean all

.PHONY: all clean fclean re
