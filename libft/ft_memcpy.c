/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:29:40 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/14 18:58:44 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*memory_dest;
	unsigned char	*memory_src;

	i = 0;
	memory_dest = (unsigned char *)dest;
	memory_src = (unsigned char *)src;
	if (src == NULL && dest == NULL)
	{
		return (dest);
	}
	while (n > i)
	{
		memory_dest[i] = memory_src[i];
		i++;
	}
	return (memory_dest);
}
