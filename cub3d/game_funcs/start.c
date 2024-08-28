/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:36 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/28 19:50:54 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	re_draw_game(t_game *game, bool right, bool up, bool move)
{
	if (right == true && up == true && !(game->player.player_x >= 6.5) && move == true)
		game->player.player_x += game->player.move_speed;
	else if (right == true && up == false && !(game->player.player_x <= -0.45) && move == true)
		game->player.player_x -= game->player.move_speed;
	else if (right == false && up == true && !(game->player.player_y <= -0.45) && move == true)
		game->player.player_y -= game->player.move_speed;
	else if (right == false && up == false && !(game->player.player_y >= 4.5) && move == true)
		game->player.player_y += game->player.move_speed;
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->img_ptr, 0, 0);
	grilled_draw(game);
	draw_player(game);
}

void	rotate_func(t_game *game, bool rotate)
{
	float	speed;

	if (rotate == true)
		speed = -game->player.rot_speed;
	if (rotate == false)
		speed = game->player.rot_speed;
	game->player.dir_x = (game->player.dir_x * cos(speed)) - (game->player.dir_y * sin(speed));
	game->player.dir_y = (game->player.dir_x * sin(speed)) + (game->player.dir_y * cos(speed));
}

int	keys(int key, t_game *game)
{
	if (key == 53)
		close_game(game);
	if (key == 2)
		re_draw_game(game, true, true, true);
	if (key == 0)
		re_draw_game(game, true, false, true);
	if (key == 1)
		re_draw_game(game, false, false, true);
	if (key == 13)
		re_draw_game(game, false, true, true);
	if (key == 123) // sol ok tuşu
	{
		rotate_func(game, true);
		re_draw_game(game, false, false, false);
	}
	if (key == 124) // sağ ok tuşu
	{
		// çizgi çizdir baktığı yöne
		//
		rotate_func(game, false);
		re_draw_game(game, false, false, false);
	}
	return (0);
}

int	main_loop(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	mlx_do_key_autorepeaton(game->mlx);
	mlx_put_image_to_window(game->mlx, game->window, game->img_ptr, 0, 0);
	draw_player(game);
	return (0);
}

int	mlx_start(t_game *game)
{
	if (create_wallpaper(game) == -1)
		return (-1);
	if (!(game->wallpaper))
		return (-1);
	mlx_hook(game->window, 17, 2, close_game, game);
	mlx_hook(game->window, 2, 1L<<0, keys, game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_loop(game->mlx);
	return (0);
}

int	start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->window = mlx_new_window(game->mlx, PIXEL * game->x_cord,
			PIXEL * game->y_cord, "Cub3D");
	if (!game->window)
		return (-1);
	if (get_images(game) == -1)
		return (-1);
	game->img_ptr = mlx_new_image(game->mlx, game->x_cord * 156,
		game->y_cord * 156);
	if (!game->img_ptr)
		return (-1);
	get_position(game);
	if (mlx_start(game) == -1)
		return (-1);
	return (0);
}
