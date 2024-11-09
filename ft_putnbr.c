/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:44:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/09 17:25:52 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrsize(int n, int base)
{
	long	nmbr;
	int		numlen;

	numlen = 0;
	nmbr = n;
	if (nmbr == 0)
		return (1);
	if (nmbr < 0)
	{
		nmbr *= -1;
		numlen++;
	}
	while (nmbr > 0)
	{
		nmbr /= base;
		numlen++;
	}
	return (numlen);
}

static int	ft_putnbr_itoa(int n, char *str, int i, char *base)
{
	long	nmbr;
	int		baselen;

	nmbr = n;
	baselen = ft_strlen(base);
	if (nmbr < 0)
	{
		str[i] = '-';
		nmbr *= -1;
		i++;
	}
	if (nmbr < baselen)
	{
		str[i] = base[nmbr];
		i++;
	}
	else
	{
		i = ft_putnbr_itoa(nmbr / baselen, str, i, base);
		str[i] = base[(nmbr % baselen)];
		i++;
	}
	return (i);
}

int	ft_putnbr_base(int n, char *base)
{
	int		i;
	char	*result;
	int		baselen;

	baselen = ft_strlen(base);
	result = (char *)malloc(ft_nbrsize(n, baselen) + 1);
	if (!result)
		return (0);
	i = ft_putnbr_itoa(n, result, 0, base);
	result[i] = '\0';
	ft_putstr(result);
	free(result);
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
