/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:13:55 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/20 18:21:18 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*second;

	i = 0;
	first = (unsigned char *) str1;
	second = (unsigned char *) str2;
	while (i < n)
	{
		if (first[i] != second[i])
		{
			return ((int)(first[i] - second[i]));
		}
		if (n == 0)
			return ((int)n);
		i++;
	}
	return (0);
}

// int	main (void)
// {
// 	char str1[]="Ola";
// 	char str2[]="Ola";
// 	int ret;
// 	int ret2;

// 	ret = ft_memcmp(str1,str2,2);
// 	   if(ret < 0) {
//       printf("str1 is less than str2\n");
//    } else if(ret > 0) {
//       printf("str2 is less than str1\n");
//    } else {
//       printf("str1 is equal to str2\n");
//    }

//    	ret2 = memcmp(str1,str2,2);
// 	   if(ret2 < 0) {
//       printf("str1 is less than str2\n");
//    } else if(ret2 > 0) {
//       printf("str2 is less than str1\n");
//    } else {
//       printf("str1 is equal to str2\n");
//    }

// }
