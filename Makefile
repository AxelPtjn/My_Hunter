##
## EPITECH PROJECT, 2022
## B-CPE-101-LYN-1-1-myprintf-axel.petitjean
## File description:
## Makefile
##

SRC		=	src/main.c \
			lib/my_printf.c \
			lib/my_putchar.c \
			lib/my_put_nbr.c \
			lib/my_putstr.c \
			lib/str_to_int.c \
			lib/my_put_table.c \
			lib/my_strlen.c \
			src/visual_game.c \
			src/game_help.c \
			src/main_bis.c \

OBJ 	= 	$(SRC:.c=.o)

NAME 	= 	my_hunter

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CSFML)
		rm $(OBJ)

$(NAME):	$(OBJ)
		gcc -o my_hunter $(OBJ) -w
		rm $(OBJ)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f *.a $(NAME)

re:		fclean all
