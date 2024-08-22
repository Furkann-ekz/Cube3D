/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:52:20 by fekiz             #+#    #+#             */
/*   Updated: 2024/08/22 15:51:47 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "stdbool.h"
# include "../mlx/mlx.h"
# include "math.h"

# include "string.h"

# define FOV 90
# define P_SPEED 1
# define R_SPEED 1
# define DARK 0x00000
# define WHITE 0xFFFFFF

typedef struct imgs
{
	void	*ea;
	void	*we;
	void	*no;
	void	*so;
	char	*no_addr;
	char	*so_addr;
	char	*ea_addr;
	char	*we_addr;
}				t_imgs;

typedef struct fds
{
	int	north;
	int	south;
	int	west;
	int	east;
}			t_files;

typedef struct dda
{
	float	playerx;
	float	playery;
	float	directx;
	float	directy;
	float	camx;
	float	camy;
}			t_dda;

typedef struct cube3d
{
	char			**map_values;
	char			**map;
	char			**map_temp;
	char			*temp;
	char			*no;
	char			*we;
	char			*so;
	char			*ea;
	char			*f;
	char			*c;
	void			*mlx;
	void			*window;
	int				*last_walls;
	int				fd;
	int				f_color;
	int				c_color;
	int				x_cord;
	int				y_cord;
	int				player_x;
	int				player_y;
	char			direction;
	struct imgs		imgs;
	struct fds		files;
	struct dda		dda;
}					t_game;

t_game	*game_data_creats(char *av);

size_t	ft_strlen(const char *str);

char	*ft_get_read(int fd);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);

int		map_find(char **map, t_game *game);
int		map_check(char **map, t_game *game);
int		give_me_textures_and_colors(char **map, t_game *game);
int		file_name_control(char *s1, char *s2);
int		line_count(t_game *game);
int		any_zero_in_outside(char **map);
int		double_new_line(char *map);
int		start(t_game *game);
int		close_game(t_game *list);
int		ft_atoi(const char *str);
int		get_images(t_game *game);

void	create_floor_and_sky(t_game *game);
void	get_free(t_game *list);
void	set_nulls(t_game *game);
void	grilled_draw(t_game *game);
void	get_position(t_game *game);

#endif
