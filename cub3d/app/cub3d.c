/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:41:45 by fekiz             #+#    #+#             */
/*   Updated: 2024/07/29 14:43:39 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (printf("Too many/few arguments\n"));
	game = game_data_creats(av[1]);
	if (!game)
		return (printf("Error: The map cannot be read.\n"));
}
