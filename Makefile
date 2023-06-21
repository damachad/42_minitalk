# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damachad <damachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 08:29:51 by damachad          #+#    #+#              #
#    Updated: 2023/06/21 11:50:52 by damachad         ###   ########.fr        #
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
	@make -C ./libft

client: client.o $(LIBFT)
	@$(CC) $(CFLAGS) $< libft/libft.a -o $@
	@echo "client created"

server: server.o $(LIBFT)
	@$(CC) $(CFLAGS) $< libft/libft.a -o $@
	@echo "server created"

bonus: $(OBJ_BNS) $(LIBFT)
	@$(CC) $(CFLAGS) client_bonus.o libft/libft.a -o client_bonus
	@$(CC) $(CFLAGS) server_bonus.o libft/libft.a -o server_bonus
	@echo "client_bonus and server_bonus created"
	
clean:
	@$(RM) $(OBJ) $(OBJ_BNS)
	@echo "minitalk objs removed"
	@make -C libft clean
	

fclean: clean
	@$(RM) client server client_bonus server_bonus
	@echo "executables removed"
	@make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
