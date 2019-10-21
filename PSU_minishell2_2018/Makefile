##
## EPITECH PROJECT, 2019
## minishell
## File description:
## minishell makefile
##

CC =		gcc

SUBCC=		make -s -C lib/

RM =		rm -f

NAME =		mysh

COMPILEFLAG =	-Wall -Wextra -pedantic -O2 -O3 -O1 -std=c99

INCLUDE =	-I./include/

USELESS_F =	*~

U_F_SRC =	$(shell find src/ -name '*~')

U_F_INC =	include/*~

U_F_LIB =	lib/*~ lib/libmy.a

LIBFLAGS =	-L./lib -lmy

CFLAGS =	$(COMPILEFLAG) $(INCLUDE) $(LIBFLAGS)

SRC	=	$(shell find src/ -name '*.c')

OBJ	=	$(SRC:.c=.o)

$(OBJDIR)%.o:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
		@$(SUBCC)
		@$(RM) $(NAME)
		@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
		@echo -e "\033[01m\033[05m\033[31m\033[03m[${NAME}]\033[00m"
		@$(RM) $(OBJ)
		@$(RM) $(OBJLIB)
		@$(RM) $(USELESS_F)
		@$(RM) $(U_F_SRC)
		@$(RM) $(U_F_INC)
		@$(RM) $(U_F_LIB)


all:		$(NAME)

clean:
		@$(RM) $(OBJ)
		@$(RM) $(USELESS_F)
		@$(RM) $(U_F_SRC)
		@$(RM) $(U_F_INC)
		@echo -e "\033[01m\033[31mRemoving objects  ...\033[00m"

fclean:		clean
		@$(RM) $(NAME)
		@echo -e "\033[01m\033[31mRemoving binary : ... {${NAME}}\033[00m"

re:		fclean all

.PHONY:		all clean fclean re
