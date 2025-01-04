/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:57:10 by ysumeral          #+#    #+#             */
/*   Updated: 2024/11/19 14:06:09 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_chr(va_arg(*args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(*args, int)));
	if (c == 'u')
		return (ft_print_uns(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 0));
	if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 1));
	if (c == '%')
		return (ft_print_chr('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(++str))
			counter += ft_check_format(*(str), &args);
		else
			counter += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (counter);
}
