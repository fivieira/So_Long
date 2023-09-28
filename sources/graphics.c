/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:19:16 by fivieira          #+#    #+#             */
/*   Updated: 2023/09/28 18:24:46 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_images_in_game(t_so_long *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer, "./images/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer, "./images/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer, "./images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer, "./images/exit.xpm", &i, &j);
	game->collectible = mlx_xpm_file_to_image(game->mlxpointer, "./images/collectible.xpm", &i, &j);
}

void	adding_in_graphics(t_so_long *game)
{
	int	height;
	int	width;

	game->collectible_count = 0;
	height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->wall, width * 32, height * 32);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->floor, width * 32, height * 32);
			if (game->map[height][width] == 'C')
			{
				mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->collectible, width * 32, height * 32);
				game->collectible_count++;
			}
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->exit, width * 32, height * 32);
			if (game->map[height][width] == 'P')
			{
				mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->player, width * 32, height * 32);
				game->x_axis = width;
				game->y_axis = height;
			}
			width++;
		}
		height++;
	}
}