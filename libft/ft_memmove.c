/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:33:27 by fivieira          #+#    #+#             */
/*   Updated: 2023/08/16 16:35:14 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t	n)
{
	unsigned char	*mem;
	unsigned char	*tocopy;

	mem = (unsigned char *) str1;
	tocopy = (unsigned char *) str2;
	if (tocopy < mem)
	{
		while (n--)
		{
			mem[n] = tocopy[n];
		}
		return (mem);
	}
	ft_memcpy(mem, tocopy, n);
	return (mem);
}
