SRCS =	main.c				\
		parsing.c			\
		libft/ft_split.c	\
		libft/ft_atol.c		\
		libft/ft_atoi.c		\
		allocate.c			\
		switch.c			\
		push.c				\
		rot.c				\
		rev_rot.c			\
		small_algo.c		\
		big_algo.c			\
		index.c				\


NAME = push_swap

OBJS = $(SRCS:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

.c.o :
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
	@echo "push_swap done !"

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all