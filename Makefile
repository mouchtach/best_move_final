NAME = push_swap

SOURCES  = push_swap.c utils/free.c utils/input.c utils/set_struct.c utils/sort.c utils/utils_push.c utils/utils_sort.c\
	operations/pa.c operations/pb.c operations/ra.c operations/rb.c \
	operations/rra.c operations/rrb.c operations/rrr.c \
	operations/sa.c operations/sb.c  operations/rr.c\
	linkedlist/creat_list.c linkedlist/ft_add_back.c linkedlist/ft_add_last.c \
	linkedlist/ft_lstclear.c linkedlist/ft_lstnew.c linkedlist/ft_lstsize.c \
	libft/ft_atoi.c libft/ft_split.c libft/ft_strdup.c libft/ft_strjoin.c \
	libft/ft_strlen.c libft/ft_substr.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
# CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
bonus: checker_bonus
	@make -C checker_bonus

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@make clean -C checker_bonus
	@rm -rf $(OBJECTS) $(BOBJECTS)

fclean: clean
	@make fclean -C checker_bonus
	@rm -rf $(NAME)

re: fclean all 