/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:45:27 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/02 10:33:42 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	can_move(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	(void)game;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'F' && map[i][j + 1] != '\0'
				&& map[i][j + 1] != 'F' && map[i][j + 1] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	character(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'E'
		&& c != 'W' && c != 'S' && c != ' ' && c != '\n')
		return (-1);
	return (0);
}

static int	last_wall(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			j++;
			if (j > count)
				count = j;
		}
		i++;
	}
	return (count);
}

static int	f_giver(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_temp[++i])
	{
		j = 0;
		while (game->map_temp[i][j] && j < game->last_wall)
		{
			if (game->map_temp[i][j] == ' ')
				game->map_temp[i][j] = 'F';
			j++;
		}
	}
	if (can_move(game->map_temp, game) == -1)
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
	game->last_wall = last_wall(game);
	f_giver(game);
	if (give_me_textures_and_colors(game) == -1)
		return (-1);
	return (0);
}
