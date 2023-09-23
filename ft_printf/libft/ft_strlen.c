/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:10:48 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/20 17:25:04 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int		x;
	size_t	count;

	x = 0;
	count = 0;
	while (str[x] != '\0')
	{
		count = x + 1;
		x++;
	}
	return (count);
}
