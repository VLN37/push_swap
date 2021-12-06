LIBFTPATH	= ./libft
LIBFT		= $(LIBFTPATH)/libft.a

SRCFILES	= push_swap.c \
			  ps_parser.c \
			  ps_validation.c \
			  ps_utils.c \
			  ps_utils2.c \
			  ps_rules.c \
			  ps_game.c \
			  ps_sorting_short.c \
			  ps_sorting_long.c \
			  ps_sorting_long2.c

BONUSFILES	= checker.c \
			  checker_parser.c \
			  checker_game.c \
			  checker_rules.c \
			  checker_utils.c \
			  checker_checker.c \
			  checker_read.c

CC			= gcc -g
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
SRCDIR		= src
BONUSDIR	= srcbonus
OBJDIR		= obj
HEADER		= push_swap.h
BONUSHEADER	= checker.h
NAME		= push_swap
BONUSNAME	= checker
INCLUDES	= -I./libft -I./
LINKS		= -I $(LIBFTPATH) -L $(LIBFTPATH) -lft

SRC		= $(addprefix $(SRCDIR)/, $(SRCFILES))
BONUSSRC= $(addprefix $(BONUSDIR)/, $(BONUSFILES))
OBJ			= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BONUSOBJ	= $(BONUSSRC:$(BONUSDIR)/%.c=$(OBJDIR)/%.o)

VPATH		= src srcbonus

all:		$(OBJDIR) $(NAME)

bonus:		$(OBJDIR) $(BONUSNAME)

complete: $(OBJDIR) $(NAME) $(BONUSNAME)

$(NAME):	$(LIBFT) $(OBJ) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKS)

$(BONUSNAME):	$(LIBFT) $(BONUSOBJ) $(BONUSHEADER)
			$(CC) $(CFLAGS) $(BONUSOBJ) -o $(BONUSNAME) $(LINKS)

$(OBJDIR)/%.o:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
			make -C $(LIBFTPATH) clean
			$(RM) $(OBJ)
			$(RM) $(BONUSOBJ)
			rm -rf obj

fclean:		clean
			make -C $(LIBFTPATH) fclean
			$(RM) $(NAME)
			$(RM) $(BONUSNAME)

$(LIBFT):
			make -C $(LIBFTPATH) all

$(OBJDIR):
			mkdir -p obj

re:			fclean all

run:		$(OBJ)
			make -C $(LIBFTPATH) all
			$(CC) $(OBJ) -o $(NAME) $(LINKS) && ./$(NAME) 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

runv:		$(OBJ)
			make -C $(LIBFTPATH) all
			$(CC) $(OBJ) -o $(NAME) $(LINKS) && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25

runs:		$(OBJ)
			make -C $(LIBFTPATH) all
			$(CC) -fsanitize=address $(OBJ) -o $(NAME) $(LINKS) && ./$(NAME) 10 9 8 7 6 5 4 3 2 1

runc:
			./push_swap $ARG | ./checker_linux $ARG

.PHONY:		all clean fclean re run runv runs runc
