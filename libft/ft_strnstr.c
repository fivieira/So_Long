/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:39:32 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/21 12:13:48 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		little_len;

	little_len = ft_strlen(little);
	if (!little_len)
		return ((char *)big);
	while (*big && little_len <= len--)
	{
		if (!ft_memcmp(big, little, little_len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char little[]="ipsum";
// 	char big[]= "lorem ipsum dolor sit amet";

// 	printf("Vamos testar vazio: %s\n", ft_strnstr(big, little,15));

// }