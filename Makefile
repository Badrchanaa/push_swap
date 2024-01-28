#/usr/bin/make

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft
LIBFLAGS = -lft -L./libft

NAME = push_swap

SOURCES = main.c utils.c push_swap.c operations.c
OBJS = $(SOURCES:.c=.o)
HEADERS = push_swap.h
LIBFT_DIR = ./libft
LIBFT_NAME = $(addprefix $(LIBFT_DIR)/, libft.a)
VPATH = src

all: $(LIBFT_NAME) $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	@echo "compiling project.."
	$(CC) $(CFLAGS) $(LIB_FLAGS) $? -o $(NAME)

$(LIBFT_NAME):
	make --directory $(LIBFT_DIR) bonus

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
