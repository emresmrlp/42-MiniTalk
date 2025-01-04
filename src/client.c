/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:12:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/05 02:05:36 by ysumeral         ###   ########.fr       */
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

static void	send_char(pid_t pid, char *c)
{
	int	i;

	i = 0;
	while (*c != '\0')
	{
		while (i < 8)
		{
			if ((*c >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
			usleep(100);
		}
		i = 0;
		c++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
		{
			str = argv[2];
			send_char(pid, str);
			ft_printf("(%s) sended to (%d)\n", str, pid);
		}
		else
			ft_printf("Invalid PID?!\n");
	}
	else
	{
		ft_printf("---------------------------\n");
		ft_printf("\n");
		ft_printf("Correct usage: ./client <pid> <string>\n");
		ft_printf("\n");
		ft_printf("---------------------------\n");
	}
	return (0);
}
