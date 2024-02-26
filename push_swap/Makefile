CFLAGS = -Wall -Wextra -Werror
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

test:	$(NAME)
		$(eval ARG = $(shell jot -r 7 0 200000000))
		./push_swap $(ARG) | ./checker $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l
#
# test_my:		$(NAME)	$(BONUS_NAME)
# 				$(eval ARG = $(shell jot -r 5 0 2000000))
# 				./push_swap $(ARG) | ./checker $(ARG)
# 				@echo -n "Instructions: "
# 				@./push_swap $(ARG) | wc -l
# 				./push_swap $(ARG)

.PHONY: all clean fclean re
