##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	= navy

CC	= gcc

RM	= rm -f

SRCS	= ./lib/src/my_getnbr.c \
	  ./lib/src/my_printf.c \
	  ./lib/src/my_put_address.c \
	  ./lib/src/my_putchar.c \
	  ./lib/src/my_putnbr.c \
	  ./lib/src/my_putnbr_base.c \
	  ./lib/src/my_putnbr_base_long.c \
	  ./lib/src/my_putnbr_long.c \
	  ./lib/src/my_putnbr_ulong.c \
	  ./lib/src/my_putstr.c \
	  ./lib/src/my_putstr_nonp.c \
	  ./lib/src/my_str_isalpha.c \
	  ./lib/src/my_str_islower.c \
	  ./lib/src/my_str_isnum.c \
	  ./lib/src/my_str_to_word_array.c \
	  ./lib/src/my_strcat.c \
	  ./lib/src/my_strcmp.c \
	  ./lib/src/my_strcpy.c \
	  ./lib/src/my_strlen.c \
	  ./src/communication.c \
	  ./src/init_map.c \
	  ./src/init_struct.c \
	  ./src/main.c \
	  ./src/navy.c \
	  ./src/print_game.c \
	  ./src/communication_init.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
