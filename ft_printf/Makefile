NAME = libftprintf.a
HEADER = ft_printf.h
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = $(addsuffix .c, ft_printf conversions extra_func more_conv)
OBJS := $(SRCS:%.c=%.o)
AR = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all