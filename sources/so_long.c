/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:14:24 by fivieira          #+#    #+#             */
/*   Updated: 2023/09/28 18:23:02 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_point(t_so_long *game)
{
	int line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
    free(game->mlxpointer);
	while (line < game->map_height - 1)
	{
		free(game->map[line]);
		line++;
	}
	free(game->map);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_so_long game;
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		exit(0);
	}
	ft_memset(&game, 0, sizeof(t_so_long));
	map_reading(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, game.map_width * 32, game.map_height * 32, "so_long");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, exit_point, 0);
	mlx_loop(game.mlxpointer);
}