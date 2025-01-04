/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:27:07 by ysumeral          #+#    #+#             */
/*   Updated: 2024/11/19 14:06:11 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uns(unsigned int uns)
{
	int	counter;

	counter = 0;
	if (uns < 10)
		counter += ft_print_chr(uns + '0');
	else
	{
		counter += ft_print_uns(uns / 10);
		counter += ft_print_uns(uns % 10);
	}
	return (counter);
}
