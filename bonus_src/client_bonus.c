/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:12:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/05 17:15:57 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"

static int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result * sign);
}

static int	send_signal(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		while (i < 8)
		{
			if ((*str >> i) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					return (-1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					return (-1);
			}
			i++;
			usleep(100);
		}
		i = 0;
		str++;
	}
	return (0);
}

static void	confirmation_handler(int signal)
{
	if (signal == SIGUSR2 || signal == SIGUSR1)
		ft_printf("+ Server: Message received! :))\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	signal(SIGUSR1, confirmation_handler);
	signal(SIGUSR2, confirmation_handler);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
		{
			str = argv[2];
			if (send_signal(pid, str) == -1)
				ft_printf("- The PID (%d) was not active!\n", pid);
		}
		else
			ft_printf("- Unexpected PID?! >:)\n");
	}
	else
		ft_printf("- Correct usage: ./client <pid> <string>\n");
	return (0);
}
