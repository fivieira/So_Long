/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:47:03 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/24 15:05:14 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*second;

	i = 0;
	first = (unsigned char *)str1;
	second = (unsigned char *)str2;
	while ((first[i] != '\0' || second[i] != '\0') && i < n)
	{
		if (first[i] != second[i])
		{
			return (first[i] - second[i]);
		}
		i++;
	}
	return (0);
}

// int	main (void)
// {
// 	char str1[]="teste\2";
// 	char str2[]="teste\0";
// 	int ret;

// 	ret = ft_strncmp(str1,str2,6);
// 	   if(ret < 0) {
//       printf("str1 is less than str2\n");
//    } else if(ret > 0) {
//       printf("str2 is less than str1\n");
//    } else {
//       printf("str1 is equal to str2\n");
//    }

// }