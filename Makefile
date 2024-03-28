#/usr/bin/make

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft -g3 # -fsanitize=address
LIB_FLAGS = -lft -L./libft

NAME = push_swap
CHECKER_NAME = checker

CHECKER_SOURCES = utils.c parse_utils.c ops_utils.c ops.c ops2.c checker.c 
SOURCES = main.c utils.c push_swap.c ops_utils.c ops.c ops2.c parse_utils.c algo.c algo_utils.c algo_utils2.c

OBJS_DIR = bin
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
CHECKER_OBJS = $(addprefix $(OBJS_DIR)/, $(CHECKER_SOURCES:.c=.o))

HEADERS = push_swap.h

LIBFT_DIR = ./libft
LIBFT_NAME = $(addprefix $(LIBFT_DIR)/, libft.a)

vpath %.c src
vpath %.h include

all: $(NAME)

bonus: $(CHECKER_NAME)

$(NAME): $(OBJS) $(LIBFT_NAME)
	@echo "compiling project.."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_FLAGS) 

$(CHECKER_NAME): $(LIBFT_NAME) $(CHECKER_OBJS)
	@echo "compiling checker.."
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER_NAME) $(LIB_FLAGS) 

$(LIBFT_NAME):
	make --directory $(LIBFT_DIR) bonus

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJS_DIR)
$(CHECKER_OBJS): | $(OBJS_DIR)

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
