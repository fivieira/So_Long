/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:12:57 by fivieira          #+#    #+#             */
/*   Updated: 2023/09/28 15:30:31 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONH_H

# include <unistd.h>
# include "get_next_line.h"
# include "printf.h"

typedef struct so_long
{
	char	**map;
    
	void	*floor;
	void	*wall;
	void	*exit;
	void	*player;
	void	*collectible;
	void	*mlxpoiner;
	void	*winpointer;
} t_so_long;

#endif