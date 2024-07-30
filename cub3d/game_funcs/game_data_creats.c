/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_creats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:07:01 by fekiz             #+#    #+#             */
/*   Updated: 2024/07/30 17:36:52 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	area_control(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[++i] == '1')
			return (i);
	}
	return (0);
}

t_game	*game_data_creats(char *av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (ft_strlen(av) < 5 || file_name_control(av, ".cub") == -1)
		return (get_free(game), NULL);
	game->fd = open(av, O_RDONLY, 0777);
	if (game->fd == -1)
		return (get_free(game), NULL);
	game->temp = ft_get_read(game->fd);
	if (!game->temp)
		return (get_free(game), NULL);
	game->map_values = ft_split(game->temp, '\n');
	if (map_find(game->map_values, game) == -1)
		return (get_free(game), NULL);
	return (game);
}
