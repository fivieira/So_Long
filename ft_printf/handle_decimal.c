/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:40 by fivieira          #+#    #+#             */
/*   Updated: 2023/05/18 12:26:24 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_negative_integer(signed long *value)
{
	int	counter;

	counter = 0;
	if (*value < 0)
	{
		ft_putchar('-');
		*value *= -1;
		counter++;
	}
	return (counter);
}

int	handle_decimal(signed long value)
{
	int		counter;
	char	*str;

	counter = handle_negative_integer(&value);
	str = ft_itoa_base(value, DECIMAL_BASE);
	counter = counter + handle_string(str);
	free(str);
	return (counter);
}
