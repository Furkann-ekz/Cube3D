/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:22:10 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/06 17:02:15 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*ft_strdup(const char *str)
{
	int		i;
	char	*str2;

	str2 = malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	if (!str2)
		return (NULL);
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

int	give_me_textures_and_colors(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_values[i])
	{
		if (game->map_values[i][0] == 'N' && game->map_values[i][1] == 'O')
			game->no = ft_strdup(game->map_values[i]);
		else if (game->map_values[i][0] == 'S' && game->map_values[i][1] == 'O')
			game->so = ft_strdup(game->map_values[i]);
		else if (game->map_values[i][0] == 'W' && game->map_values[i][1] == 'E')
			game->we = ft_strdup(game->map_values[i]);
		else if (game->map_values[i][0] == 'E' && game->map_values[i][1] == 'A')
			game->ea = ft_strdup(game->map_values[i]);
		else if (game->map_values[i][0] == 'F')
			game->f = ft_strdup(game->map_values[i]);
		else if (game->map_values[i][0] == 'C')
			game->c = ft_strdup(game->map_values[i]);
		i++;
	}
	if (!(game->no) || !(game->so) || !(game->ea)
		|| !(game->we) || !(game->c) || !(game->f))
		return (-1);
	return (0);
}
	// Karakterden sonraki kısmı alacağım. Örnek: EA için "./textures/t4.xpm"
