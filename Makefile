NAME =	pipex

HEADER =	pipex.h

FOLDER =	./src/

SRC =	$(addprefix $(FOLDER), \
		pipex.c \
		forkcp.c \
		execpath.c \
		error.c \
		freem.c)

OBJS	= ${SRC:%.c=%.o}

CC = gcc

LIBFT = ./libft/libft.a

.c.o:
	@$(CC) $(CFLAGS) -lmlx -c $< -o $@

all:$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@rm -f $(NAME)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	@make -C ./libft

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)

re: fclean all