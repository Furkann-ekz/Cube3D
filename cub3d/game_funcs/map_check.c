/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:45:27 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/07 17:26:32 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	character(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'E'
		&& c != 'W' && c != 'S' && c != ' ' && c != '\n')
		return (-1);
	return (0);
}

static int	*last_wall(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	game->last_walls = (int *)malloc(sizeof(int) * line_count(game) + 1);
	if (!(game->last_walls))
		return (NULL);
	while (game->map_temp[i])
	{
		j = 0;
		while (game->map_temp[i][j])
			j++;
		if (game->map_temp[i][j - 1] != '1')
			return (NULL);
		game->last_walls[i] = j;
		i++;
	}
	game->last_walls[i] = 0;
	return (game->last_walls);
}

static int	f_giver(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_temp[++i])
	{
		j = 0;
		while (game->map_temp[i][j])
		{
			if (game->map_temp[i][j] != ' ' && game->map_temp[i][j] != '1'
				&& game->map_temp[i][j] != '0' && game->map_temp[i][j] != 'N'
				&& game->map_temp[i][j] != 'E' && game->map_temp[i][j] != 'W'
				&& game->map_temp[i][j] != 'S')
				return (-1);
			if (game->map_temp[i][j] == ' ')
				game->map_temp[i][j] = 'F';
			j++;
		}
	}
	if (any_zero_in_outside(game->map_temp) == -1)
		return (-1);
	return (0);
}

int	map_check(char **map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (character(game->map_temp[i][j]) == -1)
				return (-1);
			j++;
		}
	}
	game->last_walls = last_wall(game);
	if (!game->last_walls)
		return (-1);
	if (f_giver(game) == -1)
		return (-1);
	if (give_me_textures_and_colors(game) == -1)
		return (-1);
	return (0);
}
