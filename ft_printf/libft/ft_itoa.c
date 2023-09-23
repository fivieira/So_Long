/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:16:30 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/24 16:23:07 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(int num)
{
	size_t	len;

	len = 1;
	if (num < 0)
		len++;
	num = num / 10;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char	*convert_itoa(char *str, size_t size,
unsigned int num, unsigned int is_negative)
{
	str[size] = '\0';
	while (size--)
	{
		str[size] = (num % 10) + 48;
		num = num / 10;
	}
	if (is_negative)
	{
		str[0] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t			n_size;
	unsigned int	is_negative;
	char			*str;

	n_size = ft_numlen(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	str = (char *)malloc(sizeof(char) * (n_size + 1));
	if (str == NULL)
		return (NULL);
	return (convert_itoa(str, n_size, (unsigned int) n, is_negative));
}

// int	main(void)
// {
// 	int num = 1454545;
// 	printf("A minha funcao: %s\n", ft_itoa(num));
// 	//printf("funcao original: %s\n", itoa(num));
// }