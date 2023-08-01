NAME = push_swap
SRCS = \
		chk_args.c \
		chk_utils.c \
		chk_single_arg.c \
		list_utils.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		sort_utils.c \
		sort_three_elements.c \
		sort_five_or_four.c \
		sort_split_insert.c \
		push_swap.c

OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


# $(NAME): $(OBJS)
# ar rcs $(NAME) $(OBJS)