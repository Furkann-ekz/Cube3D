/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:36 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/14 19:03:09 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	create_floor_and_sky(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = -1;
	while (++y <= 640)
	{
		x = -1;
		while (++x <= 1920)
			mlx_pixel_put(game->mlx, game->window, x, y, game->c_color);
	}
	y--;
	while (++y <= 1280)
	{
		x = -1;
		while (++x <= 1920)
			mlx_pixel_put(game->mlx, game->window, x, y, game->f_color);
	}
}

int	mlx_start(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1920, 1280, "Cub3D");
	if (!game->mlx || !game->window)
		return (-1);
	create_floor_and_sky(game);
	mlx_hook(game->window, 17, 2, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}

int	start(t_game *game)
{
	if (mlx_start(game) == -1)
		return (-1);
	return (0);
}
