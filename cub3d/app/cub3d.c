/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:41:45 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/08 19:32:50 by fekiz            ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (printf("Too many/few arguments\n"));
	game = game_data_creats(av[1]);
	if (game == NULL)
		return (get_free(game), printf("Error: The map cannot be read.\n"));
	if (start(game) == -1)
		return (get_free(game), printf("Error: This game can't be opened!\n"));
}
