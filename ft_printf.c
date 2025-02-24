/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:47:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/11 17:48:34 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_strhas(char *str, char c);
static int	print_format(char c, va_list args);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strhas("cspdiuxX", *str))
				len += print_format(*str, args);
			else
				len += ft_putchar(*str);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}

static int	print_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 'i' || c == 'd')
		len += ft_putnbr_base(va_arg(args, int), "0123456789", 10, 0);
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (c == 'x')
		len += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", 16, 0);
	else if (c == 'X')
		len += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", 16, 0);
	else if (c == 'u')
		len += ft_put_uint(va_arg(args, unsigned int));
	return (len);
}

static int	ft_strhas(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
