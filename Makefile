# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 19:07:04 by dehamad           #+#    #+#              #
#    Updated: 2024/04/01 13:02:21 by dehamad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
SERVER_SRC = server.c utils.c
CLIENT_SRC = client.c utils.c
BONUS_SRCS = ./bonus/client_bonus.c ./bonus/server_bonus.c

NAME = $(SERVER_NAME) $(CLIENT_NAME)
NAMES = $(NAME) $(SERVER_NAME)_bonus $(CLIENT_NAME)_bonus

all: $(NAME)

$(NAME): $(SERVER_SRC) $(CLIENT_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT) -o $(SERVER_NAME)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT) -o $(CLIENT_NAME)

bonus: $(BONUS_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o $(SERVER_NAME)_bonus
	$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o $(CLIENT_NAME)_bonus
	
$(LIBFT):
	make -C libft

sanitize: CFLAGS += -g3 -fsanitize=address

sanitize: all

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAMES) 
	make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
