/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_me_grilled_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:58:04 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/22 16:33:44 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	grilled_draw(t_game *game)
{
	int	i;
	int	y;
	int	x;

	i = -1;
	y = -1;
	while (y <= game->y_cord * 156)
	{
		x = 0;
		while (x <= 156 * game->x_cord)
		{
			if (x % 156 == 0)
			{
				i = -1;
				while (i <= game->y_cord * 156)
				{
					mlx_pixel_put(game->mlx, game->window, x, i, DARK);
					i++;
				}
			}
			mlx_pixel_put(game->mlx, game->window, x, y, DARK);
			x++;
		}
		y += 156;
	}
}
