##
## EPITECH PROJECT, 2019
## Libmy.a
## File description:
## create Libmy.a
##

SRC	=	$(shell find -name '*.c')

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../include

NAME	=	libmy.a

RM 	=	rm -f

all:		$(NAME)



$(OBJDIR)%.o:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
		@$(RM) $(NAME)
		@ar rc $(NAME) $(OBJ)
		@$(RM) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@echo -e "\033[01m\033[31mRemoving objects ...\033[00m"

fclean:		clean
	@$(RM) $(NAME)
	@echo -e "\033[01m\033[31mRemoving binary  :	{${NAME}}\033[00m"

re:	all clean
