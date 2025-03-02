NAME = ../checker

SOURCES = libft_bonus/ft_atoi_bonus.c libft_bonus/ft_split_bonus.c \
	libft_bonus/ft_strdup_bonus.c libft_bonus/ft_strjoin_bonus.c libft_bonus/ft_strlen_bonus.c libft_bonus/ft_strcmp_bonus.c \
	libft_bonus/ft_substr_bonus.c \
	linkedlist_bonus/creat_list_bonus.c linkedlist_bonus/ft_add_back_bonus.c linkedlist_bonus/ft_add_last_bonus.c \
	linkedlist_bonus/ft_lstclear_bonus.c linkedlist_bonus/ft_lstnew_bonus.c linkedlist_bonus/ft_lstsize_bonus.c \
	operations_bonus/pa_bonus.c operations_bonus/pb_bonus.c operations_bonus/ra_bonus.c operations_bonus/rb_bonus.c \
	operations_bonus/rra_bonus.c operations_bonus/rrb_bonus.c \
	operations_bonus/sa_bonus.c operations_bonus/sb_bonus.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c input_bonus.c free_bonus.c checker_bonus.c\

OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c push_swap_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
