##
## EPITECH PROJECT, 2019
## Libmy.a
## File description:
## create Libmy.a
##

SRC =	$(shell find -name '*.c')

OBJ	=	$(SRC:.c=.o)

COMPILEFLAG =	-Wall -Wextra -pedantic -O2 -O3 -O1 -std=c99 -g

CFLAGS	=	-I../include $(COMPILEFLAG)

U_F = $(shell find -name '*~')

NAME	=	libmy.a

RM 	=	rm -f

all:		$(NAME)



$(OBJDIR)%.o:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
		@$(RM) $(NAME)
		@ar rc $(NAME) $(OBJ)
		@$(RM) $(OBJ) $(U_F)

clean:
	@$(RM) $(OBJ) $(U_F)
	@echo -e "\033[01m\033[31mRemoving objects ...\033[00m"

fclean:		clean
	@$(RM) $(NAME)
	@echo -e "\033[01m\033[31mRemoving binary  :	{${NAME}}\033[00m"

re:	all clean
