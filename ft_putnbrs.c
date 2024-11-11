/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:44:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/11 17:54:02 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long nmbr, char *base, int baselen, int i)
{
	if (nmbr < 0)
	{
		i += ft_putchar('-');
		nmbr *= -1;
	}
	if (nmbr < baselen)
		i += ft_putchar(base[nmbr]);
	else
	{
		i = ft_putnbr_base(nmbr / baselen, base, baselen, i);
		i += ft_putchar(base[(nmbr % baselen)]);
	}
	return (i);
}

static int	ft_unsigned_base(unsigned long n, char *base
	, unsigned int baselen, int i)
{
	if (n >= baselen)
		i = ft_unsigned_base((n / baselen), base, baselen, i);
	i += ft_putchar(base[n % baselen]);
	return (i);
}

int	ft_putptr(void *address)
{
	unsigned long	addr;
	int				len;

	len = 0;
	if (!address)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)address;
	len += ft_putstr("0x");
	len += ft_unsigned_base(addr, "0123456789abcdef", 16, 0);
	return (len);
}

int	ft_put_uint(unsigned int nbr)
{
	int		len;

	len = 0;
	len += ft_unsigned_base(nbr, "0123456789", 10, 0);
	return (len);
}
