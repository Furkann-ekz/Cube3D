/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freee.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:57:22 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/06 17:46:08 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	double_pointers_free(t_game	*list)
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
	i = -1;
	if (list->map_temp)
	{
		while (list->map_temp[++i])
			free(list->map_temp[i]);
		free(list->map_temp);
	}
}

static void	list_imgs_free(t_game *list)
{
	if (list->imgs.w)
		free(list->imgs.w);
	if (list->imgs.c)
		free(list->imgs.c);
	if (list->imgs.z)
		free(list->imgs.z);
	if (list->imgs.e)
		free(list->imgs.e);
	if (list->imgs.p)
		free(list->imgs.p);
}

static void	pointers_free(t_game *list)
{
	if (!list)
		return ;
	if (list->m_tmp)
		free(list->m_tmp);
	if (list->temp)
		free(list->temp);
	if (list->no)
		free(list->no);
	if (list->we)
		free(list->we);
	if (list->so)
		free(list->so);
	if (list->ea)
		free(list->ea);
	if (list->f)
		free(list->f);
	if (list->c)
		free(list->c);
	if (list->last_walls)
		free(list->last_walls);
	if (list->fd)
		close(list->fd);
	list_imgs_free(list);
}

static void	give_null(t_game *list)
{
	list->map_values = NULL;
	list->map = NULL;
	list->map_temp = NULL;
	list->m_tmp = NULL;
	list->temp = NULL;
	list->no = NULL;
	list->we = NULL;
	list->so = NULL;
	list->ea = NULL;
	list->f = NULL;
	list->c = NULL;
	list->last_walls = NULL;
}

void	get_free(t_game *list)
{
	double_pointers_free(list);
	pointers_free(list);
	free(list);
	give_null(list);
}
