NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
LIB_PATH = ./libft
LIBRARY = libft.a
MAKE = make
SRC = $(addsuffix .c, pipe_test getters)

all: $(NAME)

$(LIBRARY):
	$(MAKE) -C $(LIB_PATH)

$(NAME): $(SRC) $(LIBRARY)
	$(CC) $(CFLAGS) -L $(LIB_PATH) -lft $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean all
