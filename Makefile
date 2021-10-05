LIBFTPATH	= ./libft
LIBFT		= $(LIBFTPATH)/libft.a

SRCS		= push_swap.c

#SOURCES		= $(addprefix $(SOURCES_DIR/, $(SRCS)))

OBJ			= $(SRCS:.c=.o)

NAME		= push_swap
CC			= clang
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
LINKS		= -I $(LIBFTPATH) -L $(LIBFTPATH) -lft

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<.c=.o)

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
			$(RM) $(OBJ)
			make -C $(LIBFTPATH) clean

fclean:		clean
			make -C $(LIBFTPATH) fclean
			$(RM) $(NAME)

run:
			make -C $(LIBFTPATH) all
			$(CC) main.c $(LIBFT) -o $(NAME) $(LINKS) && ./$(NAME) 1 -2

re:			fclean all
