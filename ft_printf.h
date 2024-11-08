/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:27:10 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/08 20:44:35 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr(int n);
int ft_putchar(char c);
int	ft_putstr(const char *str);

#endif
