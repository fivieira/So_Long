/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:35:45 by fivieira          #+#    #+#             */
/*   Updated: 2023/10/14 16:59:47 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_so_long *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = game->map_height;
	temporary = (char **)malloc(sizeof(char *) * (i + 2));
	if (!temporary)
		return (0);
	while (i--)
	{
		temporary[i] = game->map[i];
	}
	temporary[game->map_height + 1] = NULL;
	temporary[game->map_height] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	game->map_height++;
	return (1);
}

int	map_reading(t_so_long *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error\nInvalid file\n");
		return (0);
	}
	while (1)
	{
		readmap = get_next_line(game->fd);
		//ft_printf("%s\n",readmap);
		if (!add_line(game, readmap))
			break ;
	}
	close(game->fd);
	game->map_width = width_of_map(game->map[0]);
	return (1);
}
