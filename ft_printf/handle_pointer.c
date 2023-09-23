/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:30 by fivieira          #+#    #+#             */
/*   Updated: 2023/05/18 14:02:56 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_string(char *str)
{
	int	counter;

	counter = handle_string(str);
	return (counter);
}

static int	print_zero_exception(void)
{
	int		counter;
	char	*str;

	counter = 0;
	str = ZERO_EXCEPTION_STR;
	while (str[counter] != '\0')
		counter += ft_putchar(str[counter]);
	return (counter);
}

int	handle_pointer(void *ptr_addr)
{
	int				counter;
	char			*str;
	unsigned long	addr;

	if (ptr_addr == 0)
	{
		counter = print_zero_exception();
		return (counter);
	}
	addr = (unsigned long)ptr_addr;
	counter = print_string(PRECEDING_STR);
	str = ft_itoa_base(addr, HEX_BASE);
	counter = counter + handle_string(str);
	free(str);
	return (counter);
}
