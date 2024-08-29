/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:17:37 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/29 17:53:49 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// bir fonksiyon yaz ve "****.xpm dosyasını al"

int	get_images(t_game *game)
{
	int		x;
	int		y;
	int		z;
	char	*temp;

	temp = game->ea + 3;
	game->imgs.ea = mlx_xpm_file_to_image(game->mlx, temp, &x, &y);
	temp = game->we + 3;
	game->imgs.we = mlx_xpm_file_to_image(game->mlx, temp, &x, &y);
	temp = game->so + 3;
	game->imgs.so = mlx_xpm_file_to_image(game->mlx, temp, &x, &y);
	temp = game->no + 3;
	game->imgs.no = mlx_xpm_file_to_image(game->mlx, temp, &x, &y);
	if (!(game->imgs.ea) || !(game->imgs.we)
		|| !(game->imgs.so) || !(game->imgs.no))
		return (-1);
	game->imgs.ea_addr = mlx_get_data_addr(game->imgs.ea, &x, &y, &z);
	game->imgs.we_addr = mlx_get_data_addr(game->imgs.we, &x, &y, &z);
	game->imgs.so_addr = mlx_get_data_addr(game->imgs.so, &x, &y, &z);
	game->imgs.no_addr = mlx_get_data_addr(game->imgs.no, &x, &y, &z);
	if (!(game->imgs.ea_addr) || !(game->imgs.no_addr)
		|| !(game->imgs.we_addr) || !(game->imgs.so_addr))
		return (-1);
	return (0);
}
