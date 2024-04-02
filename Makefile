# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 19:07:04 by dehamad           #+#    #+#              #
#    Updated: 2024/04/01 18:30:59 by dehamad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
MANDATORY_SRC = utils.c
SERVER_SRC = server.c
CLIENT_SRC = client.c
BONUS_SERVER_SRC = ./bonus/server_bonus.c
BONUS_CLIENT_SRC = ./bonus/client_bonus.c

NAME = $(SERVER) $(CLIENT)
BONUS_NAME = $(SERVER_BONUS) $(CLIENT_BONUS)

all: $(NAME)

bonus: $(BONUS_NAME)

$(SERVER): $(SERVER_SRC) $(MANDATORY_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

$(CLIENT): $(CLIENT_SRC) $(MANDATORY_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

$(SERVER_BONUS): $(BONUS_SERVER_SRC) $(MANDATORY_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

$(CLIENT_BONUS): $(BONUS_CLIENT_SRC) $(MANDATORY_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@
	
$(LIBFT):
	make -C libft

sanitize: CFLAGS += -g3 -fsanitize=address

sanitize: all

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
