/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:26:16 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/13 12:20:08 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

int	ft_printf(const char *key, ...);

int	ft_putstr(char *str);

int	print_hexadec(unsigned int p, char *charset);

int	print_pointer(unsigned long int p);

int	ft_putnbr_unsigned(unsigned int nb, int numdigit);

int	ft_putnbr(int nb, int numdigit);

#endif
