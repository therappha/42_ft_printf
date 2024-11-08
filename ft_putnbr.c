/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:44:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/08 20:45:06 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrsize(int n)
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
		nmbr /= 10;
		numlen++;
	}
	return (numlen);
}

static int	ft_putnbr_itoa(int n, char *str, int i)
{
	long	nmbr;

	nmbr = n;
	if (nmbr < 0)
	{
		str[i] = '-';
		nmbr *= -1;
		i++;
	}
	if (nmbr < 10)
	{
		str[i] = nmbr + '0';
		i++;
	}
	else
	{
		i = ft_putnbr_itoa(nmbr / 10, str, i);
		str[i] = (nmbr % 10) + '0';
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;
	char	*result;

	result = (char *)malloc(ft_nbrsize(n) + 1);
	if (!result)
		return (0);
	i = ft_putnbr_itoa(n, result, 0);
	result[i] = '\0';
	ft_putstr(result);
	free(result);
	return (i);
}
