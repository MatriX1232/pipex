CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

LIBFT_DIR = libft/

FILES = \
	pipex.c \
	utils.c \

OBJS = ${FILES:.c=.o}

%.c: %.o
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: all
