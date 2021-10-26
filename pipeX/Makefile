NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIB_PATH = ./libft
LIBRARY = libft.a
MAKE = make
SRC = $(addsuffix .c, main getters cmd_list)
OBJ = $(SRC:c=o)

all: $(NAME)

$(LIBRARY):
	$(MAKE) -C $(LIB_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -L $(LIB_PATH) -lft -o $@ $^
	$(RM) $^

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all