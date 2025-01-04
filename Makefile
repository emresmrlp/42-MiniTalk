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
	@$(CC) $(CFLAGS) $(PRINTF_LIB) src/server.c -o server
	@$(CC) $(CFLAGS) $(PRINTF_LIB) src/client.c -o client
	@echo ---------------------------
	@echo
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

.PHONY: all fclean clean re