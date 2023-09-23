/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:23:51 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/29 15:19:26 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

//  int main (void)
//  {
// 	char str[]= "Eu .tenho";
//  	printf("Minha funcao: %s\n", ft_strchr(str,'.'));
//  }