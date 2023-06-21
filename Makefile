# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damachad <damachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 08:29:51 by damachad          #+#    #+#              #
#    Updated: 2023/06/21 15:09:51 by damachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFT = libft/libft.a
SRC = client.c server.c
SRC_BNS = client_bonus.c server_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)

all: client server

client: client.o $(LIBFT)
	$(CC) $(CFLAGS) $< libft/libft.a -o $@

server: server.o $(LIBFT)
	$(CC) $(CFLAGS) $< libft/libft.a -o $@

$(LIBFT):
	make -C ./libft

bonus: $(OBJ_BNS) $(LIBFT)
	$(CC) $(CFLAGS) client_bonus.o libft/libft.a -o client_bonus
	$(CC) $(CFLAGS) server_bonus.o libft/libft.a -o server_bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJ) $(OBJ_BNS)
	make -C ./libft clean

fclean: clean
	$(RM) client server client_bonus server_bonus ./libft/libft.a

re: fclean all

.PHONY: all bonus clean fclean re
