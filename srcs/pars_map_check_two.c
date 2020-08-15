/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_check_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:29:21 by coline            #+#    #+#             */
/*   Updated: 2020/08/15 17:09:22 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_space(int **map, int h, int w, int *size)
{
	if ((map[h][w] == 7 || map[h][w] == 8)
	&& ((h != size[1] - 1 && (map[h + 1][w] != 1
	&& map[h + 1][w] != 8 && map[h + 1][w] != 7))
	|| (h != 0 && (map[h - 1][w] != 1
	&& map[h - 1][w] != 8 && map[h - 1][w] != 7))
	|| (w != size[0] - 1 && (map[h][w + 1] != 1
	&& map[h][w + 1] != 8 && map[h][w + 1] != 7))
	|| (w != 0 && (map[h][w - 1] != 1
	&& map[h][w - 1] != 8 && map[h][w - 1] != 7))))
		return (-1);
	else if ((h == size[1] - 1 || w == size[0] - 1
	|| h == 0 || w == 0) && (map[h][w] != 1
	&& map[h][w] != 7 && map[h][w] != 8))
		return (-1);
	else if (last_line(map, size[0], h))
		return (-2);
	return (0);
}

int		last_line(int **map, int width, int h)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[h][i] != 8 && map[h][i] != 7)
			return (0);
		i++;
	}
	return (1);
}
