LIBFTPATH	= ./libft
LIBFT		= $(LIBFTPATH)/libft.a

SRCS		= ps_parser.c \
              ps_validation.c \
              push_swap.c

#SOURCES		= $(addprefix $(SOURCES_DIR/, $(SRCS)))
OBJ			= $(SRCS:.c=.o)

NAME		= push_swap
CC			= clang
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
LINKS		= -I $(LIBFTPATH) -L $(LIBFTPATH) -lft


all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFTPATH) all
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKS)

.c.o:
			$(CC) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJ)
			make -C $(LIBFTPATH) clean

fclean:		clean
			make -C $(LIBFTPATH) fclean
			$(RM) $(NAME)

run:		$(OBJ)
			make -C $(LIBFTPATH) all
			$(CC) $(OBJ) -o $(NAME) $(LINKS) && ./$(NAME) 1 -2

re:			fclean all

.PHONY:		all clean fclean re run libft libftpath
