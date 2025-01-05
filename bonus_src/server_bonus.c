/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:09:00 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/05 17:07:51 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"

static void	signal_handler(int signal, siginfo_t *info, void *parameter)
{
	static int	received_char = 0;
	static int	bit_position = 0;

	(void) parameter;
	if (signal == SIGUSR2)
		received_char |= 1 << bit_position;
	bit_position++;
	if (bit_position == 8)
	{
		ft_printf("%c", (char)received_char);
		if (received_char == 0)
			ft_printf("- Invalid character!");
		received_char = 0;
		bit_position = 0;
	}
	if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
	else if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("---------------------------\n");
	ft_printf("\n");
	ft_printf("( BONUS ) SERVER STARTED!\n");
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Waiting for a string..\n");
	ft_printf("\n");
	ft_printf("---------------------------\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
