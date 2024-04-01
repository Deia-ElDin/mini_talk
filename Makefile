# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 19:07:04 by dehamad           #+#    #+#              #
#    Updated: 2024/04/01 09:53:54 by dehamad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
SERVER_SRC = server.c
CLIENT_SRC = client.c

NAME = $(SERVER_NAME) $(CLIENT_NAME)

all: $(NAME)

$(NAME): $(SERVER_SRC) $(CLIENT_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT) -o $(SERVER_NAME)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT) -o $(CLIENT_NAME)

$(LIBFT):
	make -C libft

sanitize: CFLAGS += -fsanitize=address

sanitize: all

clean:
	make -C libft clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
