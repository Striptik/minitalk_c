NAME		= client

SRC		= client.c

OBJ		= $(SRC:.c=.o)

CC		= cc

CP		= cp

RM		= rm -f

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lmy -L../
	$(CP) $(NAME) ../
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
