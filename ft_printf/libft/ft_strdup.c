/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:01:45 by fivieira          #+#    #+#             */
/*   Updated: 2023/05/18 11:27:49 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

// int	main(void)
// {
// 	char *str = "Hello, ";
// 	char *mine = NULL;
// 	char *function = NULL;

// 	mine = ft_strdup(str);
// 	function = strdup(str);
// 	printf("Copiado: %s\n",mine);
// 	printf("Real function: %s\n",function);
// }