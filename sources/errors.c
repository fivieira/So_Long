/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:34:41 by fivieira          #+#    #+#             */
/*   Updated: 2023/10/14 18:27:49 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontal_wall(t_so_long *game)
{
	int	i;
	int	j;

	i = game->map_width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][j] != '1' || game->map[game->map_height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	vertical_wall(t_so_long *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->map_width;
	while (height < game->map_height)
	{
		if (game->map[height][0] != '1' || game->map[height][width - 1] != '1')
			return (0);
		height++;
	}
	return (1);
}

void	check_walls(t_so_long *game)
{
	int	vertical_walls;
	int	horizontal_walls;

	vertical_walls = vertical_wall(game);
	horizontal_walls = horizontal_wall(game);
	if (!vertical_walls || !horizontal_walls)
	{
		ft_printf("Error\nThis map is missing the walls\n");
		exit_point(game);
	}
	if (check_format(game) == 0)
	{
		ft_printf("Map is not a rectangle.\n");
		exit_point(game);
	}
}

static void	count_checker(t_so_long *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("\nError Here!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->collectible_count++;
	if (game->map[height][width] == 'P')
		game->player_count++;
	if (game->map[height][width] == 'E')
		game->exit_count++;
}

void	check_caracters(t_so_long *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map_height - 1)
	{
		width = 0;
		while (width <= game->map_width)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->player_count == 1 && game->collectible_count >= 1 
			&& game->exit_count == 1))
	{
		ft_printf("Error\n");
		ft_printf("This map is invalid (player or exixt or Collectible)\n");
		exit_point(game);
	}
}
