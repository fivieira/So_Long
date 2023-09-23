/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:03:31 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/28 15:59:55 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_len;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!*s1 || !*set)
		return (ft_strdup(s1));
	str_len = ft_strlen(s1) + 1;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = str_len;
	while (start < end && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, (end - start)));
}

// int	 main(void)
// {
// 	char str[] = "";
// 	char str1[] = "";

// 	printf("Funcao trim: %s\n", ft_strtrim(str,""));
// 	printf("Comparacao: %d\n", ft_strncmp(str, str1, 1));
// 	//printf("Funcao original trim: %s\n", strtrim(str," "));
// }