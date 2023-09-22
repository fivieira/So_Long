/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:27:07 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/15 17:43:46 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (dest[len] && len < size)
	{
		len++;
	}
	i = len;
	while (src[len - i] && (len + 1) < size)
	{
		dest[len] = src[len - i];
		len++;
	}
	if (i < size)
	{
		dest[len] = '\0';
	}
	return (i + ft_strlen(src));
}

// int	main(void)
// {
// 	char dest[]="t3";
// 	char src[]="Eu";
// 	printf("A minha string: %d\n",ft_strlcat(dest,src,2));
// }