SRCS =	main.c				\
		parsing.c			\
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
	@echo "Push_Swap Done !\n"
	@$(MAKE) -C libft
	@$(CC) $(CC_FLAGS) $(OBJS) libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all