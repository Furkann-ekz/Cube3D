/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:40:59 by fekiz             #+#    #+#             */
/*   Updated: 2024/07/29 18:42:17 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	file_name_control(char *s1, char *s2)
{
	int	i;
	int	j;
	int	fd;

	j = 3;
	i = 0;
	while (s1[i])
		i++;
	i--;
	while (s1[i] == s2[j])
	{
		i--;
		j--;
		if (j == -1)
			return (0);
	}
	fd = open(s1, O_RDONLY, 0777);
	if (fd != -1)
	{
		close (fd);
		return (0);
	}
	return (-1);
}
