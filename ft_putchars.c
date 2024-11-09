/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:21:14 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/09 21:30:09 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));


	i = 0;
	while (*str)
	{
		i += ft_putchar(*str);
		str++;
	}
	return (i);
}
