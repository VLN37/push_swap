LIBFTPATH	= ./libft
LIBFT		= $(LIBFTPATH)/libft.a

SRCS		= push_swap.c \
			  ps_parser.c \
			  ps_validation.c \
			  ps_utils.c \
			  ps_rules1.c


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
			$(CC) $(OBJ) -o $(NAME) $(LINKS) && ./$(NAME) 1 2 3 4 5 6 7 8 9

runv:		$(OBJ)
			make -C $(LIBFTPATH) all
			$(CC) $(OBJ) -o $(NAME) $(LINKS) && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 1 2 3 4 5 6 7 8 9

runs:		$(OBJ)
			make -C $(LIBFTPATH) all
			$(CC) -fsanitize=address $(OBJ) -o $(NAME) $(LINKS) && ./$(NAME) 1 2 3 4 5 6 7 8 9

re:			fclean all

.PHONY:		all clean fclean re run libft libftpath
