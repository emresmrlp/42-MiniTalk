/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:09:00 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/05 02:05:31 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"

static void	signal_handler(int signal)
{
	static int	received_char = 0;
	static int	bit_position = 0;

	if (signal == SIGUSR2)
		received_char |= 1 << bit_position;
	bit_position++;
	if (bit_position == 8)
	{
		ft_printf("%c", (char)received_char);
		if (received_char == 0)
			ft_printf("Invalid character!");
		received_char = 0;
		bit_position = 0;
	}
}

int	main(void)
{
	ft_printf("---------------------------\n");
	ft_printf("\n");
	ft_printf("Server started!\n");
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Waiting for a string..\n", getppid());
	ft_printf("\n");
	ft_printf("---------------------------\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
