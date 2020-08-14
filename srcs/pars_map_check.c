/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:40:45 by coline            #+#    #+#             */
/*   Updated: 2020/08/13 16:04:52 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map(int **map, int height, int width, t_cub *cub)
{
	if (check_char_map(map, height, width))
		return (ft_error_two(1, cub));
	else if (height <= 1 || width <= 1)
		return (ft_error_two(2, cub));
	else if (check_leak_map(map, height, width))
		return (ft_error_two(3, cub));
	else if (check_player(map, height, width))
		return (ft_error_two(4, cub));
	else
		return (0);
}

int		check_leak_map(int **map, int height, int width)
{
	int w;
	int h;

	w = 0;
	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			if ((map[h][w] == 7 || map[h][w] == 8)
			&& ((h != height - 1 && map[h + 1][w] == 0)
			|| (h != 0 && map[h - 1][w] == 0)
			|| (w != width - 1 && map[h][w + 1] == 0)
			|| (w != 0 && map[h][w - 1] == 0)))
				return (-1);
			else if ((h == height - 1 || w == width - 1
			|| h == 0 || w == 0) && (map[h][w] != 1
			&& map[h][w] != 7 && map[h][w] != 8))
				return (-1);
			w++;
		}
		h++;
	}
	return (0);
}

int		check_player(int **map, int height, int width)
{
	int i;
	int j;
	int player;

	i = 0;
	j = 0;
	player = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (map[j][i] > 2 && map[j][i] < 7)
				player++;
			i++;
		}
		j++;
	}
	if (player == 0 || player > 1)
		return (-1);
	return (0);
}

int		ischarmap(char c)
{
	if (c == '1' || c == '2' || c == '0')
		return (0);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	if (c == ' ')
		return (2);
	return (-1);
}

int		check_char_map(int **map, int height, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (map[j][i] < 0)
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}
