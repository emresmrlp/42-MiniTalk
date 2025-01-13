# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 17:18:37 by ysumeral          #+#    #+#              #
#    Updated: 2025/01/12 17:53:36 by ysumeral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
PRINTF_LIB = ./ft_printf/libftprintf.a

$(NAME): all

all:
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./src/server.c $(PRINTF_LIB) -o $(SERVER)
	$(CC) $(CFLAGS) ./src/client.c $(PRINTF_LIB) -o $(CLIENT)
	@echo ---------------------------
	@echo
	@echo " -- MANDATORY PART --"
	@echo " SERVER and CLIENT are ready!"
	@echo " (by ysumeral)"
	@echo
	@echo ---------------------------

clean:
	make clean -C ./ft_printf

fclean:
	make fclean -C ./ft_printf
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

bonus: fclean
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./bonus_src/server_bonus.c $(PRINTF_LIB) -o $(SERVER)
	$(CC) $(CFLAGS) ./bonus_src/client_bonus.c $(PRINTF_LIB) -o $(CLIENT)
	@echo ---------------------------
	@echo
	@echo " -- BONUS PART --"
	@echo " SERVER and CLIENT are ready!"
	@echo " (by ysumeral)"
	@echo
	@echo ---------------------------

.PHONY: all fclean clean re bonus