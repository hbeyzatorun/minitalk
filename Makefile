NAME_SERVER = server
NAME_CLIENT = client

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC_SERVER = server.c helper.c
SRC_CLIENT = client.c helper.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all:$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re:	fclean all

.PHONY: all clean fclean re