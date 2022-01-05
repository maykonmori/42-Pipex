NAME =	pipex

HEADER =	pipex.h

INCLUDE = -I ./

FOLDER =	./src/

FOLDER2 = ./utils/

UTILS = $(addprefix $(FOLDER2), \
		ft_split.c\
		ft_strdup.c\
		ft_strlcpy.c\
		ft_strjoin.c\
		ft_bzero.c\
		ft_strlen.c\
		ft_strtrim.c)

SRC =	$(addprefix $(FOLDER), \
		pipex.c \
		forkcp.c \
		execpath.c \
		error.c \
		freem.c \
		init.c)




OBJS	= ${SRC:%.c=%.o} ${UTILS:%.c=%.o}

CC = clang

CFLAGS = -Wextra -Werror -Wall -g

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:$(NAME)

$(NAME): $(OBJS)
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# -fsanitize=leak