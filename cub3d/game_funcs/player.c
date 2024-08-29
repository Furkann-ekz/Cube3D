/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:23:56 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/29 18:02:39 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	keys(int key, t_game *game)
{
	if (key == 53)
		return (close_game(game));
	if (key == 2)
		re_draw_game(game, true, true, true);
	if (key == 0)
		re_draw_game(game, true, false, true);
	if (key == 1)
		re_draw_game(game, false, false, true);
	if (key == 13)
		re_draw_game(game, false, true, true);
	if (key == 123) // sol ok tuşu
	{
		rotate_func(game, true);
		re_draw_game(game, false, false, false);
	}
	if (key == 124) // sağ ok tuşu
	{
		// çizgi çizdir baktığı yöne
		//
		rotate_func(game, false);
		re_draw_game(game, false, false, false);
	}
	return (0);
}

void	rotate_func(t_game *game, bool rotate)
{
	float	speed;

	if (rotate == true)
		speed = -game->player.rot_speed;
	if (rotate == false)
		speed = game->player.rot_speed;
	game->player.dir_x = (game->player.dir_x * cos(speed))
		- (game->player.dir_y * sin(speed));
	game->player.dir_y = (game->player.dir_x * sin(speed))
		+ (game->player.dir_y * cos(speed));
}

int	draw_player(t_game *game)
{
	int	i;
	int	j;

	i = (game->player.player_y * PIXEL) + PIXEL / 2 - 5;
	while (++i <= (game->player.player_y * PIXEL) + PIXEL / 2 + 5)
	{
		j = (game->player.player_x * PIXEL) + PIXEL / 2 - 5;
		while (++j <= (game->player.player_x * PIXEL) + PIXEL / 2 + 5)
			mlx_pixel_put(game->mlx, game->window, j, i, DARK);
	}
	draw_player_two(game);
	return (0);
}

int	draw_player_two(t_game *game)
{
	int	i;
	int	j;

	i = ((game->player.player_y + game->player.dir_y) * PIXEL)
		+ PIXEL / 2 -2;
	while (++i <= ((game->player.player_y + game->player.dir_y) * PIXEL)
		+ PIXEL / 2 + 2)
	{
		j = ((game->player.player_x + game->player.dir_x) * PIXEL)
			+ PIXEL / 2 - 2;
		while (++j <= ((game->player.player_x + game->player.dir_x) * PIXEL)
			+ PIXEL / 2 + 2)
			mlx_pixel_put(game->mlx, game->window, j, i, DARK);
	}
	return (0);
}

void	get_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'S')
			{
				game->player.player_x = j;
				game->player.player_y = i;
			}
		}
	}
}
