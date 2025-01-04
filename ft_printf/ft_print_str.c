/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:09:26 by ysumeral          #+#    #+#             */
/*   Updated: 2024/11/19 14:06:14 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		return (ft_print_str("(null)"));
	while (*str)
	{
		counter += ft_print_chr(*str);
		str++;
	}
	return (counter);
}
