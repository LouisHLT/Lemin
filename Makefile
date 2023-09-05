##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for bsq
##

SRC_FILES	=	parsing/parsing.c			\
				parsing/display_anthill.c	\
				parsing/open_file.c			\
				parsing/check_rooms.c		\
				utils/linked_lists_utils.c	\
				utils/utils_algo.c			\
				algo/create_graph.c			\
				algo/process_graph.c		\
				algo/dijkstra.c				\
				algo/display_moves.c		\

SRC	=	$(addprefix src/, $(SRC_FILES)	\
		free.c							\
		engine.c)

LIB = 	$(addprefix lib/my/,    \
		my_putstr.c				\
		my_strlen.c				\
		my_memcpy.c				\
		my_realloc.c			\
		my_str_to_word_array.c	\
		my_putchar.c			\
		my_strchr.c				\
		my_strcmp.c				\
		my_strdup.c				\
		my_strcpy.c				\
		my_atoi.c				\
		my_printf.c				\
		my_array_len.c			\
		my_calloc.c				\
		my_memset.c				\
		my_is_digit.c)

INCLUDE	=	-I ./include/ -L./lib/ -lmy -g3

CFLAGS	+=	$(INCLUDE)

UT_NAME	=	unit_tests

UTFLAGS	=	--coverage -lcriterion

UT_DIR = tests/tests_lemin.c

OBJ	+=	$(SRC:.c=.o)

OBJL	=	$(LIB:.c=.o)

NAME	=	lem_in

all:	compile
		make clean

lib.a:	$(OBJL)
		ar rc libmy.a $(OBJL)
		mv libmy.a ./lib/

compile:	$(OBJ) lib.a
			gcc -o $(NAME) main.c $(OBJ) $(CFLAGS)

tests_run:	$(OBJ) lib.a
			gcc -o $(UT_NAME) $(SRC) $(LIB) $(UT_DIR) $(CFLAGS) $(UTFLAGS)
			./$(UT_NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJL)

fclean: clean
	rm -f $(NAME)
	rm -f ./lib/libmy.a
	rm -f $(UT_NAME)
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.o

re: fclean all

.PHONY: all lib.a compile clean fclean re
