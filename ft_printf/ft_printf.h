/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:31:51 by fivieira          #+#    #+#             */
/*   Updated: 2023/05/18 14:01:30 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

# define HEX_BASE			"0123456789abcdef"
# define HEX_BASE_UPPER		"0123456789ABCDEF"
# define DECIMAL_BASE		"0123456789"
# define PRECEDING_STR		"0x"
# define EXCEPTION_STR		"(null)"
# define ZERO_EXCEPTION_STR	"(nil)"

int		ft_printf(const char *str, ...);
int		handle_argument_format(int c, va_list args);
int		handle_char(char c);
int		handle_string(char *str);
int		handle_pointer(void *ptr_addr);
int		handle_decimal(signed long value);
int		handle_unsigned_decimal(unsigned int value);
int		handle_hexadecimal(unsigned int value);
int		handle_hexadecimal_upper(unsigned int value);
int		handle_percent(char c);
int		is_argument(int c);

#endif