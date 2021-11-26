CLIENT		= ./client/client

SERVER		= ./server/server

SRC_CLIENT	= ./client/client.c 

SRC_SERVER	= ./server/server.c \
			./server/lib.c

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

CC		= cc

CFLAGS		+= -Wall -Wextra -Werror

RM		= rm -f

NAME = $(SERVER) $(CLIENT)

.PHONY: all
all: $(SERVER) $(CLIENT)

./server/%.o: ./server/%.c ./server/server.h
	cc -Wall -Wextra -Werror -g -c $< -o $@

$(SERVER):	$(OBJ_SERVER) ./server/server.h
		$(CC) -o $(SERVER) $(OBJ_SERVER) 

$(CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(CLIENT) $(OBJ_CLIENT)

.PHONY: clean
clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

.PHONY: fclean
fclean:		clean
		$(RM) $(SERVER) $(CLIENT)

.PHONY: re
re:		fclean all
