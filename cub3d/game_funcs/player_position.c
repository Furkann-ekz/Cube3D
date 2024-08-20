/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:23:56 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/20 15:43:57 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	dda_edit(char c, t_game *game)
{
	if (c == 'N')
	{
		game->dda.directx = 0;
		game->dda.directy = -1;
	}
	else if (c == 'E')
	{
		game->dda.directx = 1;
		game->dda.directy = 0;
	}
	else if (c == 'W')
	{
		game->dda.directx = -1;
		game->dda.directy = 0;
	}
	else if (c == 'S')
	{
		game->dda.directx = 0;
		game->dda.directy = 1;
	}
}

void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			dda_edit(game->map[i][j], game);
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S')
			{
				game->dda.camx = 0.66;
				game->dda.camy = 0;
			}
			else if (game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->dda.camx = 0;
				game->dda.camy = 0.66;
			}
		}
	}
}
