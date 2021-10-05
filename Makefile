LIBFTPATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRCS		= push_swap.c

#SOURCES		= $(addprefix $(SOURCES_DIR/, $(SRCS)))

OBJ			= $(SRCS:.c=.o)

NAME		= push_swap
CC			= clang
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<.c=.o)

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

run:
			$(CC) main.c

re:			fclean all
