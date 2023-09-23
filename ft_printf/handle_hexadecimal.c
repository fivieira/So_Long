/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:37 by fivieira          #+#    #+#             */
/*   Updated: 2023/05/18 10:20:51 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hexadecimal(unsigned int value)
{
	int		counter;
	char	*str;

	str = ft_itoa_base(value, HEX_BASE);
	counter = handle_string(str);
	free(str);
	return (counter);
}

int	handle_hexadecimal_upper(unsigned int value)
{
	int		counter;
	char	*str;

	str = ft_itoa_base(value, HEX_BASE_UPPER);
	counter = handle_string(str);
	free(str);
	return (counter);
}
