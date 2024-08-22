/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:36 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/22 14:56:30 by fekiz            ###   ########.fr       */
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

int	start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->window = mlx_new_window(game->mlx, 156 * game->x_cord, 156 * game->y_cord, "Cub3D");
	if (!game->window)
		return (-1);
	if (get_images(game) == -1)
		return (-1);
	grilled_draw(game);
	get_position(game);
	printf("%d\n%d\n", game->player_x, game->player_y);
	mlx_pixel_put(game->mlx, game->window, game->player_x * 156 + 78, game->player_y * 156 + 78, game->c_color);
	// player konumunu belirle
	// playerı çiz (tek piksel olacak unutma)
	// ışınları çiz
	//create_floor_and_sky(game);
	if (mlx_start(game) == -1)
		return (-1);
	return (0);
}
