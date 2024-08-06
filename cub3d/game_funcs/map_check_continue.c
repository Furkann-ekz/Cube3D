/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_continue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:27:54 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/06 19:08:25 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	line_count(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_temp[i])
		i++;
	return (i);
}

int	any_zero_in_outside(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'F' && )
				// F'in etrafında 1'den veya F'ten başka karakter olamaz. Bunun kontrolünü düzenlemeliyim.
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
//			((map[i][j + 1] && map[i][j + 1] != 'F' && map[i][j + 1] != '1')
//				|| (map[i + 1][j] && map[i + 1][j] != '1' && map[i + 1][j] != 'F')
//				|| (i > 0 && map[i - 1][j] && map[i - 1][j] != '1' && map[i - 1][j] != 'F'))
