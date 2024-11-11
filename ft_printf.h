/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:27:10 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/11 17:23:59 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr_base(long nnmbr, char *base, int baselen, int i);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putptr(void *address);
int	ft_put_uint(unsigned int nbr);

#endif
