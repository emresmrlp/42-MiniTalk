NAME = minitalk
SERVER = server
CLIENT = client
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
PRINTF_LIB = ./ft_printf/libftprintf.a

$(NAME): all

all:
	@make -s -C ./ft_printf
	@$(CC) $(CFLAGS) $(PRINTF_LIB) src/server.c -o $(SERVER)
	@$(CC) $(CFLAGS) $(PRINTF_LIB) src/client.c -o $(CLIENT)
	@echo ---------------------------
	@echo
	@echo " -- MANDATORY PART --"
	@echo " SERVER and CLIENT are ready!"
	@echo " (by ysumeral)"
	@echo
	@echo ---------------------------

clean:
	@make clean -s -C ./ft_printf

fclean: clean
	@make fclean -s -C ./ft_printf
	@$(RM) $(SERVER) $(CLIENT)

re: fclean all

bonus: fclean
	@make -s -C ./ft_printf
	@$(CC) $(CFLAGS) $(PRINTF_LIB) bonus_src/server_bonus.c -o $(SERVER)
	@$(CC) $(CFLAGS) $(PRINTF_LIB) bonus_src/client_bonus.c -o $(CLIENT)
	@echo ---------------------------
	@echo
	@echo " -- BONUS PART --"
	@echo " SERVER and CLIENT are ready!"
	@echo " (by ysumeral)"
	@echo
	@echo ---------------------------

.PHONY: all fclean clean re bonus