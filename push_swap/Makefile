NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rc
RM = rm -f
LIB_PATH = ./libft
LIBRARY = libft.a
MAKE = make

SRCS = $(addsuffix .c, main error_check pass_args rotates swaps_and_pushes rev_rotates little_sorts)
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(LIBRARY):
	$(MAKE) -C $(LIB_PATH)

$(NAME): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIB_PATH) -lft
	$(RM) $(OBJS)

push: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIB_PATH) -lft
	$(RM) $(OBJS)

clean:
	$(RM) $(OBJS) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all