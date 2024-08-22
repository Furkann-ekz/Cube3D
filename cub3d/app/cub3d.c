/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:41:45 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/21 18:38:49 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_nulls(t_game *game)
{
	game->map_values = NULL;
	game->map = NULL;
	game->map_temp = NULL;
	game->temp = NULL;
	game->no = NULL;
	game->we = NULL;
	game->so = NULL;
	game->ea = NULL;
	game->f = NULL;
	game->c = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->last_walls = NULL;
	game->imgs.ea = NULL;
	game->imgs.no = NULL;
	game->imgs.so = NULL;
	game->imgs.we = NULL;
}

char	get_direction(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S')
				return (map[i][j]);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (printf("Too many/few arguments\n"));
	game = game_data_creats(av[1]);
	if (game == NULL)
		return (get_free(game), printf("Error: The map cannot be read.\n"));
	game->direction = get_direction(game->map);
	if (game->direction == 0)
		return (get_free(game), printf("Error: Direction error.\n"));
	if (start(game) == -1)
		return (get_free(game), printf("Error: This game can't be opened!\n"));
}
