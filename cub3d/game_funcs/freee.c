/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freee.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:57:22 by fekiz             #+#    #+#             */
/*   Updated: 2024/07/30 14:01:39 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	game_values_free(t_game	*list)
{
	int	i;

	i = -1;
	if (!list)
		return ;
	if (list->map_values)
	{
		while (list->map_values[++i])
			free(list->map_values[i]);
		free(list->map_values);
	}
	i = -1;
	if (list->map)
	{
		while (list->map[++i])
			free(list->map[i]);
		free(list->map);
	}
	if (list->fd)
		close(list->fd);
	if (list->m_tmp)
		free(list->m_tmp);
	if (list->temp)
		free(list->temp);
}

void	get_free(t_game *list)
{
	game_values_free(list);
	free(list);
}
