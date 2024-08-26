/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:36 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/26 17:30:10 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
A = 0
S = 1
D = 2
W = 13
<- = 123
-> = 124
*/

int	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = game->player_y - 5;
	create_floor_and_sky(game);
	grilled_draw(game);
	while (++i <= game->player_y + 5)
	{
		j = game->player_x - 5;
		while (++j <= game->player_y + 5)
			mlx_pixel_put(game->mlx, game->window, i, j, DARK);
	}
	return (0);
}

int	mlx_start(t_game *game)
{
	mlx_hook(game->window, 17, 2, close_game, game);
	mlx_key_hook(game->window, keys, game);
	mlx_loop(game->mlx);
	return (0);
}

int	start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->window = mlx_new_window(game->mlx, PIXEL * game->x_cord,
			PIXEL * game->y_cord, "Cub3D");
	if (!game->window)
		return (-1);
	if (get_images(game) == -1)
		return (-1);
	get_position(game);
	draw_map(game);
	if (mlx_start(game) == -1)
		return (-1);
	return (0);
}
