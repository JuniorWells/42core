NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIB_PATH = ./libft
LIBRARY = libft.a
MAKE = make
SRC = $(addsuffix .c, main getters cmd_list extra errors)
OBJ = $(SRC:c=o)

all: $(NAME)

$(LIBRARY):
	$(MAKE) -C $(LIB_PATH)

$(NAME): $(OBJ) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L $(LIB_PATH) -lft

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all