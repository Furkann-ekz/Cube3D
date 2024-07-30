/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:39:00 by fekiz             #+#    #+#             */
/*   Updated: 2024/07/29 18:46:15 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}

char	*ft_get_read(int fd)
{
	char	*liner;
	char	*str;
	int		rd;

	liner = malloc(41);
	rd = 1;
	if (!liner)
		return (NULL);
	while (rd > 0)
	{
		rd = read(fd, liner, 40);
		if (rd < 0)
		{
			free(liner);
			return (NULL);
		}
		liner[rd] = '\0';
		if (rd > 0)
			str = ft_strjoin(str, liner);
	}
	liner[ft_strlen(liner) - 1] = '\0';
	free(liner);
	return (str);
}
