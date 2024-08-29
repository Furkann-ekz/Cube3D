/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:58:04 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/29 18:00:31 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	grilled_draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->y_cord * PIXEL)
	{
		x = 0;
		while (x < PIXEL * game->x_cord)
		{
			if (x % PIXEL == 0 || y % PIXEL == 0)
				game->wallpaper[x + y * game->x_cord * PIXEL] = DARK;
			x++;
		}
		y++;
	}
}

void	re_draw_game(t_game *game, bool right, bool up, bool move)
{
	if (right == true && up == true && !(game->player.player_x >= 6.5)
		&& move == true)
		game->player.player_x += game->player.move_speed;
	else if (right == true && up == false && !(game->player.player_x <= -0.45)
		&& move == true)
		game->player.player_x -= game->player.move_speed;
	else if (right == false && up == true && !(game->player.player_y <= -0.45)
		&& move == true)
		game->player.player_y -= game->player.move_speed;
	else if (right == false && up == false && !(game->player.player_y >= 4.5)
		&& move == true)
		game->player.player_y += game->player.move_speed;
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->img_ptr, 0, 0);
	draw_player(game);
}
