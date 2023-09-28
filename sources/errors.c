/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:34:41 by fivieira          #+#    #+#             */
/*   Updated: 2023/09/28 18:12:42 by fivieira         ###   ########.fr       */
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
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	vertical_wall(t_so_long *game)
{
	int	i;
	int	j;

	i = game->map_height;
	j = 0;
	while (j < i)
	{
		if (game->map[j][0] != '1' || game->map[j][i - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

static void check_walls(t_so_long *game)
{
	int	vertical_walls;
	int	horizontal_walls;

	vertical_walls = vertical_wall(game);
	horizontal_walls = horizontal_wall(game);
	
	if (!vertical_walls || !horizontal_walls)
	{
		printf("Error\nThis map is missing the walls\n");
		exit_point(game);
	}
}

static void	count_checker(t_so_long *game, int height, int width)
{
	if (game->map[height][width] != '1' && 
		game->map[height][width] != '0' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != '\n')
	{
		printf("\nError Here!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'P')
		game->player_count++;
	if (game->map[height][width] == 'E')
		game->exit_count++;
	if (game->map[height][width] == 'C')
		game->collectible_count++;	
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
	if (!(game->player_count == 1 && game->column_count > 1 && game->exit_count == 1))
	{
		printf("Error\nThis map is missing the player, the exit or the collectibles\n");
		exit_point(game);
	}
}

void	check_errors(t_so_long *game)
{
	check_walls(game);
	check_caracters(game);
}