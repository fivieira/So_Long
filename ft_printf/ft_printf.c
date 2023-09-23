/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:22:35 by fivieira          #+#    #+#             */
/*   Updated: 2023/05/18 12:19:51 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_input(const char *str, va_list args)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != '%')
			counter += ft_putchar(str[i]);
		else if ((str[i] == '%') && str[i + 1])
		{
			i++;
			if (is_argument(str[i]))
				counter = counter + handle_argument_format(str[i], args);
			else if (str[i])
				counter = counter + ft_putchar(str[i]);
		}
		i++;
	}
	return (counter);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	const char	*str;
	int			counter;

	counter = 0;
	str = ft_strdup(fmt);
	if (!str)
		return (0);
	va_start(args, fmt);
	counter = counter + handle_input(str, args);
	va_end(args);
	free((void *)str);
	return (counter);
}
