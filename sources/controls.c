/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:14:24 by fivieira          #+#    #+#             */
/*   Updated: 2023/10/07 16:37:45 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	right_move(t_so_long *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectible_count != 0)
			return (0);
		ft_printf("\nYou Have Won, Congrats!\n");
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectible_count--;
		game->counter++;
	}
	return (1);
}

static int	keyboard_w_s(t_so_long *game, int movement)
{
	int		dy;
	int		i;
	int		j;
	char	current_cell;

	dy = 0;
	i = game->x_axis;
	j = game->y_axis;
	if (movement == 'w' || movement == 65362)
		dy = -1;
	else if (movement == 's' || movement == 65364)
		dy = 1;
	if (dy != 0)
	{
		j += dy;
		current_cell = game->map[j][i];
		if (current_cell != '1' && right_move(game, i, j))
		{
			game->map[j - dy][i] = '0';
			ft_printf("Movements: %d\n", game->counter);
			ft_printf("Collectables: %d\n", game->collectible_count);
			return (1);
		}
	}
	return (0);
}

static int	keyboard_a_d(t_so_long *game, int movement)
{
	int		dx;
	int		i;
	int		j;
	char	current_cell; 

	dx = 0;
	i = game->x_axis;
	j = game->y_axis;
	if (movement == 'a' || movement == 65361)
		dx = -1;
	else if (movement == 'd' || movement == 65363)
		dx = 1;
	if (dx != 0)
	{
		i += dx;
		current_cell = game->map[j][i];
		if (current_cell != '1' && right_move(game, i, j))
		{
			game->map[j][i - dx] = '0';
			ft_printf("Movements: %d\n", game->counter);
			ft_printf("Collectables: %d\n", game->collectible_count);
			return (1);
		}
	}
	return (0);
}

int	controls_working(int command, t_so_long *game)
{
	int	works;

	if (command == 65307)
		exit_point(game);
	if (command == 'w' || command == 65362)
		works = keyboard_w_s(game, command);
	if (command == 's' || command == 65364)
		works = keyboard_w_s(game, command);
	if (command == 'a' || command == 65361)
		works = keyboard_a_d(game, command);
	if (command == 'd' || command == 65363)
		works = keyboard_a_d(game, command);
	if (works)
		adding_in_graphics(game);
	return (1);
}
