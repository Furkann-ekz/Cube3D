/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:22:10 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/08 19:30:08 by fekiz            ###   ########.fr       */
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

int	get_colors(t_game *game)
{
	char	**ccolor;
	char	**fcolor;
	int		i;

	i = -1;
	ccolor = ft_split(game->c + 2, ',');
	if (!ccolor)
		return (-1);
	fcolor = ft_split(game->f + 2, ',');
	if (!fcolor)
		return (-1);
	game->c_color = (ft_atoi(ccolor[0]) << 16)
		| (ft_atoi(ccolor[1]) << 8) | ft_atoi(ccolor[2]);
	game->f_color = (ft_atoi(fcolor[0]) << 16)
		| (ft_atoi(fcolor[1]) << 8) | ft_atoi(fcolor[2]);
	while (ccolor[++i])
		free(ccolor[i]);
	free(ccolor);
	i = -1;
	while (fcolor[++i])
		free(fcolor[i]);
	free(fcolor);
	return (0);
}

int	can_we_open_files(t_game *game)
{
	game->files.east = open((game->ea + 3), O_RDONLY, 0777);
	game->files.north = open((game->no + 3), O_RDONLY, 0777);
	game->files.south = open((game->so + 3), O_RDONLY, 0777);
	game->files.west = open((game->we + 3), O_RDONLY, 0777);
	if (game->files.east == -1 || game->files.north == -1
		|| game->files.south == -1 || game->files.west == -1)
		return (-1);
	close (game->files.east);
	close (game->files.north);
	close (game->files.south);
	close (game->files.west);
	if (get_colors(game) == -1)
		return (-1);
	return (0);
}

int	give_me_textures_and_colors(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == 'N' && map[i][1] == 'O' && map[i][2] == ' ')
			game->no = ft_strdup(map[i]);
		else if (map[i][0] == 'S' && map[i][1] == 'O' && map[i][2] == ' ')
			game->so = ft_strdup(map[i]);
		else if (map[i][0] == 'W' && map[i][1] == 'E' && map[i][2] == ' ')
			game->we = ft_strdup(map[i]);
		else if (map[i][0] == 'E' && map[i][1] == 'A' && map[i][2] == ' ')
			game->ea = ft_strdup(map[i]);
		else if (map[i][0] == 'F' && map[i][1] == ' ')
			game->f = ft_strdup(map[i]);
		else if (map[i][0] == 'C' && map[i][1] == ' ')
			game->c = ft_strdup(map[i]);
		i++;
	}
	if (!(game->no) || !(game->so) || !(game->ea)
		|| !(game->we) || !(game->c) || !(game->f))
		return (-1);
	if (can_we_open_files(game) == -1)
		return (-1);
	return (0);
}
