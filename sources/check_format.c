/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:55:14 by fivieira          #+#    #+#             */
/*   Updated: 2023/10/14 17:56:01 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(t_so_long *game)
{
	size_t	i;
	size_t	width;

	i = 0;
	width = game->map_width;
	while (game->map[i] != NULL)
	{
		if (ft_strlen(game->map[i]) != (width + 1))
			return (0);
		i++;
	}
	return (1);
}
