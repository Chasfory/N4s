##
## EPITECH PROJECT, 2021
##
## File description:
##

SRC			=	src/main.c				\
				src/str_to_word_array.c	\
				src/check_run.c			\
				src/check_direction.c	\
				src/nfours.c			\

OBJ			=	$(SRC:.c=.o)

NAME		=	ai

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include

CC			=	gcc

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

./PHONY: all clean fclean