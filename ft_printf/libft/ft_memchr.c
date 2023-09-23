/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:40:35 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/29 15:22:24 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*tosearch;

	i = 0;
	tosearch = (char *) str;
	while (i < n)
	{
		if ((unsigned char)tosearch[i] == (unsigned char)c)
		{
			return ((char *)(tosearch + i));
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char str[] = "/|\x12\xff\x09\0\x42\042\0\42|\\";

// 	printf("Minha funcao: %s\n",ft_memchr(str,'\0',12));
// 	printf("funcao Original: %s\n",memchr(str,'\0',12));

// }
