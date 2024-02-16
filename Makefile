#/usr/bin/make

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft
LIB_FLAGS = -lft -L./libft
NAME = push_swap
CHECKER_NAME = checker
CHECKER_SOURCES = utils.c parse_utils.c ops_utils.c ops_a.c ops_b.c checker.c 
SOURCES = main.c utils.c push_swap.c ops_utils.c ops_a.c ops_b.c parse_utils.c algo.c
OBJS = $(SOURCES:.c=.o)
CHECKER_OBJS = $(CHECKER_SOURCES:.c=.o)
HEADERS = push_swap.h
LIBFT_DIR = ./libft
LIBFT_NAME = $(addprefix $(LIBFT_DIR)/, libft.a)
VPATH = src

all: $(NAME)

bonus: $(CHECKER_NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	@echo "compiling project.."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_FLAGS) 

$(CHECKER_NAME): $(LIBFT_NAME) $(CHECKER_OBJS)
	@echo "compiling checker.."
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER_NAME) $(LIB_FLAGS) 

$(LIBFT_NAME):
	make --directory $(LIBFT_DIR) bonus

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(CHECKER_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER_NAME)
	make -C $(LIBFT_DIR) fclean
re: fclean all

.PHONY: clean fclean re
