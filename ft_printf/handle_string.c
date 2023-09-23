/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:26 by fivieira          #+#    #+#             */
/*   Updated: 2023/05/18 12:18:40 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_string(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		str = EXCEPTION_STR;
	while (str[counter] != '\0')
	{
		counter = counter + ft_putchar(str[counter]);
	}
	return (counter);
}
