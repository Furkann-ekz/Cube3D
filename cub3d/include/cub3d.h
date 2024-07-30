/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:52:20 by fekiz             #+#    #+#             */
/*   Updated: 2024/07/30 15:58:35 by fekiz            ###   ########.fr       */
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

typedef struct imgs
{
	void	*w;
	void	*c;
	void	*z;
	void	*e;
	void	*p;
}				t_imgs;

typedef struct cube3d
{
	char		**map_values;
	char		**map;
	char		*m_tmp;
	char		*temp;
	int			fd;
	int			last_wall;
	struct imgs	imgs;
}				t_game;

t_game	*game_data_creats(char *av);
size_t	ft_strlen(char *str);
int		file_name_control(char *s1, char *s2);
char	*ft_get_read(int fd);
char	**ft_split(char *s, char c);
void	get_free(t_game *list);
int		map_find(char **map, t_game *game);
int		map_check(char **map, t_game *game);

#endif
