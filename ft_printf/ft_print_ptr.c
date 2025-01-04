/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:44 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/05 01:14:46 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				counter;
	unsigned long	n;

	counter = 0;
	n = (unsigned long) ptr;
	if (!ptr)
		return (ft_print_str("(nil)"));
	counter += ft_print_str("0x");
	counter += ft_print_base(n, "0123456789abcdef");
	return (counter);
}
