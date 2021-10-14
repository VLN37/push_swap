LIBFTPATH	= ./libft
LIBFT		= $(LIBFTPATH)/libft.a

SRCS		= push_swap.c \
			  ps_parser.c \
			  ps_validation.c \
			  ps_utils.c \
			  ps_utils2.c \
			  ps_rules.c \
			  ps_game.c \
			  ps_sorting.c \
			  ps_sorting2.c


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
			$(CC) $(OBJ) -o $(NAME) $(LINKS) && ./$(NAME) 10 9 8 7 6 5 4 3 2 1

runv:		$(OBJ)
			make -C $(LIBFTPATH) all
			$(CC) $(OBJ) -o $(NAME) $(LINKS) && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

runs:		$(OBJ)
			make -C $(LIBFTPATH) all
			$(CC) -fsanitize=address $(OBJ) -o $(NAME) $(LINKS) && ./$(NAME) 9 8 7 6 5 4 3 2

runc:
			./push_swap $ARG | ./checker_linux $ARG

rundebug:	$(OBJ)
			make -C $(LIBFTPATH) all
			clang push_swap.o ps_parser.o ps_validation.o ps_utils.o ps_utils2.o ps_rules.o ps_game.o ps_sorting.o ps_sorting2.o -o push_swap -I ./libft -L ./libft -lft -D DEBUG && ./push_swap 10 9 8 7 6 5 4 3 2 1

re:			fclean all

.PHONY:		all clean fclean re run libft libftpath
