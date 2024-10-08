/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freee.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:57:22 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/29 17:51:02 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	double_pointers_free(t_game	*list)
{
	int	i;

	i = -1;
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

void	list_imgs_free(t_game *list)
{
	if (list->imgs.so)
		free(list->imgs.so);
	if (list->imgs.no)
		free(list->imgs.no);
	if (list->imgs.ea)
		free(list->imgs.ea);
	if (list->imgs.we)
		free(list->imgs.we);
	if (list->imgs.ea_addr)
		free(list->imgs.ea_addr);
	if (list->imgs.no_addr)
		free(list->imgs.no_addr);
	if (list->imgs.so_addr)
		free(list->imgs.so_addr);
	if (list->imgs.we_addr)
		free(list->imgs.we_addr);
}

static void	pointers_free(t_game *list)
{
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

void	get_free(t_game *list)
{
	if (list)
	{
		double_pointers_free(list);
		pointers_free(list);
		free(list);
		list = NULL;
	}
	//system("leaks cub3d");
}

int	close_game(t_game *list)
{
	mlx_destroy_image(list->mlx, list->img_ptr);
	mlx_destroy_window(list->mlx, list->window);
	get_free(list);
	exit (0);
}
