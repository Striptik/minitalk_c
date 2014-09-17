NAME1		= client

NAME2		= server

SRC_CLI		= client_dir/client.c

SRC_SERV	= server_dir/server.c

OBJ_CLI		= $(SRC_CLI:.c=.o)

OBJ_SERV	= $(SRC_SERV:.c=.o)

CC		= cc

CP		= cp

RM		= rm -f

LIB		= -lmy -L./

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ_CLI)
	cd my/; make
	$(CC) -o $(NAME1) $(OBJ_CLI) $(LIB)
	$(CP) $(NAME1) client_dir/.

$(NAME2): $(OBJ_SERV)
	$(CC) -o $(NAME2) $(OBJ_SERV) $(LIB)
	$(CP) $(NAME2) server_dir/.

clean:
	$(RM) $(OBJ_CLI)
	$(RM) $(OBJ_SERV)

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)
	$(RM) client_dir/$(NAME1)
	$(RM) server_dir/$(NAME2)

re: fclean all

.PHONY: all clean fclean re
