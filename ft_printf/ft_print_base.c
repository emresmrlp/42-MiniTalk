/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:00:53 by ysumeral          #+#    #+#             */
/*   Updated: 2024/11/19 14:10:28 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(unsigned long n, char *base)
{
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		counter += ft_print_base(n / 16, base);
	}
	counter += ft_print_chr(base[n % 16]);
	return (counter);
}
