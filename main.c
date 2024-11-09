/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:01:09 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/09 17:27:29 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s!\n", "World");
	ft_printf("Hello %d!\n", 25);
	ft_printf("Hello %d and %i!\n", -42, 42);
	ft_printf("this is a %c!\n", 'x');
	ft_printf("this is 10 in hex: %x\n", 10);
	ft_printf("this is 10 in HEX: %X\n", 10);
	ft_printf("Original:\n");
	printf("this is 10 in hex: %x\n", 10);
	printf("this is 10 in HEX: %X\n", 10);
}
