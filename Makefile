# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damachad <damachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 08:29:51 by damachad          #+#    #+#              #
#    Updated: 2023/06/20 14:02:54 by damachad         ###   ########.fr        #
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

$(LIBFT):
	make -C ./libft

client: client.o $(LIBFT)
	$(CC) $(CFLAGS) $< libft/libft.a -o $@

server: server.o $(LIBFT)
	$(CC) $(CFLAGS) $< libft/libft.a -o $@

bonus: $(OBJ_BNS) $(LIBFT)
	$(CC) $(CFLAGS) client_bonus.o libft/libft.a -o client_bonus
	$(CC) $(CFLAGS) server_bonus.o libft/libft.a -o server_bonus
	
clean:
	$(RM) $(OBJ) $(OBJ_BNS)
	make -C libft clean

fclean: clean
	$(RM) client server libft/libft.a client_bonus server_bonus

re: fclean all

.PHONY: all bonus clean fclean re
