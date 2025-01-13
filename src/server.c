/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:09:00 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/12 17:32:48 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

static void	signal_handler(int signal)
{
	static int	received_char = 0;
	static int	bit_position = 0;

	if (signal == SIGUSR2)
		received_char |= 1 << bit_position;
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
	ft_printf("---------------------------\n");
	ft_printf("\n");
	ft_printf("( MANDATORY ) SERVER STARTED!\n");
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Waiting for a string..\n");
	ft_printf("\n");
	ft_printf("---------------------------\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
