/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:36 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/22 16:40:48 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	keys(int key, t_game *game)
{
	if (key == 53)
		close_game(game);
	return (0);
}

int	mlx_start(t_game *game)
{
	mlx_hook(game->window, 17, 2, close_game, game);
	mlx_key_hook(game->window, keys, game);
	mlx_loop(game->mlx);
	return (0);
}

void	draw_ray(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = game->player_x;
	y = game->player_y;
	while (x <= game->player_x + 45)
	{
		y = game->player_y;
		while (--y >= 0)
			mlx_pixel_put(game->mlx, game->window, x, y, DARK);
		if (count == 45)
			x++;
		count++;
	}
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
	create_floor_and_sky(game);
	grilled_draw(game);
	get_position(game);
	mlx_pixel_put(game->mlx, game->window,
		game->player_x, game->player_y, DARK);
	draw_ray(game);
	if (mlx_start(game) == -1)
		return (-1);
	return (0);
}
