/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:23:56 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/28 19:51:30 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	draw_player(t_game *game)
{
	int	i;
	int	j;

	i = (game->player.player_y * 156) + 78 - 5;
	while (++i <= (game->player.player_y * 156) + 78 + 5)
	{
		j = (game->player.player_x * 156) + 78- 5;
		while (++j <= (game->player.player_x * 156) + 78 + 5)
			mlx_pixel_put(game->mlx, game->window, j, i, DARK);
	}
	draw_player_two(game);
	return (0);
}

int	draw_player_two(t_game *game)
{
	int	i;
	int	j;

	i = ((game->player.player_y + game->player.dir_y) * 156) + 78 -2;
	while (++i <= ((game->player.player_y + game->player.dir_y) * 156) + 78 + 2)
	{
		j = ((game->player.player_x + game->player.dir_x) * 156) + 78 - 2;
		while (++j <= ((game->player.player_x + game->player.dir_x) * 156) + 78 + 2)
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
