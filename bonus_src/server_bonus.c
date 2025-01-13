/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:09:00 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/12 17:32:50 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk_bonus.h"

static void	signal_handler(int signal, siginfo_t *info, void *parameter)
{
	static int	received_char = 0;
	static int	bit_position = 0;

	(void) parameter;
	if (signal == SIGUSR2)
	{
		received_char |= 1 << bit_position;
		kill(info->si_pid, SIGUSR2);
	}
	else
		kill(info->si_pid, SIGUSR1);
	bit_position++;
	if (bit_position == 8)
	{
		if (received_char == 0)
			ft_printf("- Invalid character!");
		else
			write(1, &received_char, 1);
		received_char = 0;
		bit_position = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
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
