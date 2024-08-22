/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:17:37 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/21 15:27:36 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// bir fonksiyon yaz ve "****.xpm dosyasını al"

int	take_the_files(t_game *game, char *temp, char *s1)
{
	int		x;
	int		y;
	char	*s2;
	char	*s3;
	char	*s4;

	temp = ft_strdup("./");
	s1 = ft_strjoin(temp, game->ea + 5);
	s2 = ft_strjoin(temp, game->no + 5);
	s3 = ft_strjoin(temp, game->so + 5);
	s4 = ft_strjoin(temp, game->we + 5);
	if (!temp || !s1 || !s2 || !s3 || !s4)
		return (-1);
	game->imgs.ea = mlx_xpm_file_to_image(game->mlx, s1, &x, &y);
	game->imgs.no = mlx_xpm_file_to_image(game->mlx, s2, &x, &y);
	game->imgs.so = mlx_xpm_file_to_image(game->mlx, s3, &x, &y);
	game->imgs.we = mlx_xpm_file_to_image(game->mlx, s4, &x, &y);
	free(temp);
	free(s1);
	free(s2);
	free(s3);
	free(s4);
	return (0);
}

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
