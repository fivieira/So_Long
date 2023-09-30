/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:12:57 by fivieira          #+#    #+#             */
/*   Updated: 2023/09/30 17:24:41 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
#include <fcntl.h>
# include "get_next_line.h"
# include "printf.h"
# include "../ft_printf/libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct so_long
{
	int		fd;
	int		map_width;
	int		map_height;
	int		player_count;
	int		column_count;
	int		exit_count;
	int		collectible_count;
	int		counter;
	int		x_axis;
	int		y_axis;

	char	**map;

	void	*floor;
	void	*wall;
	void	*exit;
	void	*player;
	void	*collectible;
	void	*mlxpointer;
	void	*winpointer;
}	t_so_long;

int	exit_point(t_so_long *so_long);
int	map_reading(t_so_long *so_long, char **argv);
void check_errors(t_so_long *so_long);
void place_images_in_game(t_so_long *so_long);
void adding_in_graphics(t_so_long *so_long);
int	controls_working(int command, t_so_long *game);

#endif
