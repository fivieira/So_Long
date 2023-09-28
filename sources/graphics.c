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